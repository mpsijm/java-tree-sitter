package com.github.mpsijm.treesittergenerate;

import junit.framework.*;
import org.apache.maven.it.*;
import org.apache.maven.it.util.*;

import java.io.*;
import java.nio.file.*;
import java.util.*;

// Example test taken from https://maven.apache.org/plugin-developers/plugin-testing.html#integration-functional-testing
public class TreeSitterGenerateTest extends TestCase {
    public void testJavaGitRepo() throws Exception {
        File testDir = ResourceExtractor.simpleExtractResources(getClass(), "/test-project/java-git-repo");

        Verifier verifier = new Verifier(testDir.getAbsolutePath());
        verifier.displayStreamBuffers();

        verifier.executeGoals(Arrays.asList("clean", "install"));

        verifier.verifyErrorFreeLog();
        verifier.verifyTextInLog("Cloning https://github.com/tree-sitter/tree-sitter-java.git");
        verifier.verifyTextInLog("Executing `gcc`");

        Path javaLibraryPath = testDir.toPath().resolve(Paths.get(
                "target", "classes", "com", "github", "mpsijm", "javatreesitter", "java"));
        verifier.assertFilePresent(javaLibraryPath.resolve("TreeSitterJavaLibrary.class").toString());
        verifier.assertFilePresent(
                javaLibraryPath.resolve(Paths.get("lib", "darwin_universal", "libtreesitterjava.dylib")).toString());

        verifier.resetStreams();
    }

    public void testToyGrammar() throws Exception {
        File testDir = ResourceExtractor.simpleExtractResources(getClass(), "/test-project/toy-grammar");

        Verifier verifier = new Verifier(testDir.getAbsolutePath());
        verifier.displayStreamBuffers();

        verifier.executeGoals(Arrays.asList("clean", "install"));

        verifier.verifyErrorFreeLog();
        verifier.verifyTextInLog("Executing `gcc`");

        Path javaLibraryPath = testDir.toPath().resolve(Paths.get(
                "target", "classes", "com", "github", "mpsijm", "javatreesitter", "toy"));
        verifier.assertFilePresent(javaLibraryPath.resolve("TreeSitterToyLibrary.class").toString());
        verifier.assertFilePresent(
                javaLibraryPath.resolve(Paths.get("lib", "darwin_universal", "libtreesittertoy.dylib")).toString());

        verifier.resetStreams();
    }
}
