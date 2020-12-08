package com.github.mpsijm.treesittergenerate;

import org.apache.maven.plugin.*;
import org.apache.maven.project.*;
import org.eclipse.jgit.api.*;
import org.eclipse.jgit.api.errors.*;

import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

/**
 * Goal which generates TreeSitter bindings for a given language.
 *
 * @goal generate
 * @phase generate-sources
 */
public class TreeSitterGenerateMojo extends AbstractMojo {
    /**
     * The Maven Project. We'll add a new source directory to this project if everything is successful.
     *
     * @parameter expression="${project}"
     * @readonly
     * @required
     */
    private MavenProject project;

    /**
     * @parameter expression="${project.build.directory}"
     * @readonly
     * @required
     */
    private File targetDir;

    /**
     * The name of the language to generate bindings for. By default, the name of the repository is used.
     *
     * @parameter
     */
    private String languageName;

    /**
     * One of the following options:
     * - The URL to the Git repository of the language that you want to generate TreeSitter bindings for.
     * - The path to a local directory containing a language that you want to generate TreeSitter bindings for.
     *
     * @parameter
     * @required
     */
    private String languageRepository;

    public void execute() throws MojoExecutionException {
        String languageName = (this.languageName == null ? urlToName(this.languageRepository) : this.languageName)
                .toLowerCase();
        String LanguageName = Character.toUpperCase(languageName.charAt(0)) + languageName.substring(1);
        boolean isExternalRepo = this.languageRepository.startsWith("http");
        File languageDir = isExternalRepo
                ? targetDir.toPath().resolve("tree-sitter-language").resolve(languageName).toFile()
                : new File(this.languageRepository);

        if (isExternalRepo) {
            if (languageDir.exists()) {
                try {
                    getLog().info("Updating " + languageRepository);
                    Git.open(languageDir).pull();
                } catch (IOException e) {
                    throw new MojoExecutionException("Failed to update languageRepository " + languageRepository, e);
                }
            } else {
                try {
                    getLog().info("Cloning " + languageRepository);
                    Git.cloneRepository().setURI(languageRepository).setDirectory(languageDir).call();
                } catch (GitAPIException e) {
                    throw new MojoExecutionException("Failed to clone languageRepository " + languageRepository, e);
                }
            }
        } else {
            getLog().info("Using " + languageDir.getAbsolutePath());
        }

        // If the parser has not been generated yet from the grammar, try to do so.
        // This assumes that `tree-sitter` is on the PATH.
        // This step is not necessary for pre-generated languages (e.g. the officially supported TreeSitter languages).
        if (!languageDir.toPath().resolve("src").resolve("parser.c").toFile().exists()) {
            try {
                getLog().info("Executing `tree-sitter generate`");
                ProcessBuilder builder = new ProcessBuilder("tree-sitter", "generate");
                builder.directory(languageDir.getAbsoluteFile());
                builder.redirectErrorStream(true);
                builder.inheritIO();
                Process process = builder.start();

                int exitCode = process.waitFor();
                if (exitCode != 0) {
                    throw new MojoExecutionException("`tree-sitter generate` exited with status code " + exitCode);
                }
            } catch (IOException e) {
                throw new MojoExecutionException("Failed to run `tree-sitter generate`", e);
            } catch (InterruptedException e) {
                throw new MojoExecutionException("`tree-sitter generate` was interrupted", e);
            }
        }

        // Library locations defined at https://code.google.com/archive/p/bridj/wikis/LibrariesLookup.wiki
        Path classesPath = targetDir.toPath().resolve(Paths.get("classes",
                "com", "github", "mpsijm", "javatreesitter", languageName, "lib", "linux_x64")); // TODO multi-arch
        classesPath.toFile().mkdirs();
        Path librarySOPath = classesPath.resolve("libtreesitter" + languageName + ".so");

        try {
            getLog().info("Executing `gcc`");
            ProcessBuilder builder = new ProcessBuilder("gcc", "src/parser.c", "-Isrc/", "-std=c99", "-shared", "-fPIC",
                    "-o", librarySOPath.toAbsolutePath().toString());
            getLog().info(String.join(" ", builder.command()));
            builder.directory(languageDir.getAbsoluteFile());
            builder.inheritIO();
            Process process = builder.start();

            int exitCode = process.waitFor();
            if (exitCode != 0) {
                throw new MojoExecutionException("`gcc` exited with status code " + exitCode);
            }
        } catch (IOException e) {
            throw new MojoExecutionException("Failed to run `gcc`", e);
        } catch (InterruptedException e) {
            throw new MojoExecutionException("`gcc` was interrupted", e);
        }

        Path sourcesRootPath = targetDir.toPath().resolve(Paths.get("generated-sources", "tree-sitter"));
        Path sourcesPath = sourcesRootPath.resolve(
                Paths.get("com", "github", "mpsijm", "javatreesitter", languageName));
        sourcesPath.toFile().mkdirs();
        Path libraryJavaPath = sourcesPath.resolve("TreeSitter" + LanguageName + "Library.java");

        try (InputStream templateStream = getClass().getClassLoader()
                .getResourceAsStream("com/github/mpsijm/treesittergenerate/LanguageLibrary.java.template")) {
            String template = new BufferedReader(new InputStreamReader(templateStream)).lines().collect(Collectors.joining("\n"))
                    .replaceAll("\\$languageName", languageName).replaceAll("\\$LanguageName", LanguageName);
            Files.write(libraryJavaPath, template.getBytes());
        } catch (IOException e) {
            throw new MojoExecutionException("IOException while writing TreeSitter" + LanguageName + "Library.java", e);
        }

        project.addCompileSourceRoot(sourcesRootPath.toFile().getAbsolutePath());
    }

    private String urlToName(String languageRepository) {
        String[] split = languageRepository.split("/");
        return split[split.length - 1].replace(".git", "");
    }
}
