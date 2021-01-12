# java-tree-sitter
_Java bindings for https://github.com/tree-sitter/tree-sitter._

## Dependencies
- `java`
- `maven`
- `gcc`
- `tree-sitter` (optional, only if you want to generate parsers from grammars, see comment in [TreeSitterGenerateMojo](tree-sitter-generate-maven-plugin/src/main/java/com/github/mpsijm/treesittergenerate/TreeSitterGenerateMojo.java) about `tree-sitter generate`)

## Getting Started

- `mvn install` will install both projects to your local Maven repository (default `~/.m2/repository`)
- Add dependency to POM:
    ```xml
    <dependencies>
      <dependency>
        <groupId>com.github.mpsijm</groupId>
        <artifactId>java-tree-sitter</artifactId>
        <version>0.0.1-SNAPSHOT</version>
      </dependency>
    </dependencies>
    ```
- Add language binding generator to POM:
    ```xml
    <build>
      <plugins>
        <plugin>
          <groupId>com.github.mpsijm</groupId>
          <artifactId>tree-sitter-generate-maven-plugin  </artifactId>
          <version>0.0.1-SNAPSHOT</version>
          <executions>
            <execution>
              <id>Generate bindings for Java</id>
              <phase>generate-sources</phase>
              <goals>
                <goal>generate</goal>
              </goals>
              <configuration>
                <languageRepository>https://github.com/tree-sitter/tree-sitter-java.git</languageRepository>
                <languageName>Java</languageName>
              </configuration>
            </execution>
          </executions>
        </plugin>
      </plugins>
    </build>
    ```
- Create tree sitter parser:
    ```java
    import org.bridj.Pointer;
    import com.github.mpsijm.javatreesitter.TSLanguage;
    import com.github.mpsijm.javatreesitter.TSParser;
    import com.github.mpsijm.javatreesitter.java.TreeSitterLibrary;
    import static com.github.mpsijm.javatreesitter.JavaTreeSitterLibrary.*;

    // ...

        Pointer<TSLanguage> javaLanguage = TreeSitterJavaLibrary.tree_sitter_java();

        Pointer<TSParser> parser = ts_parser_new();
        ts_parser_set_language(parser, javaLanguage);
    ```
- Parse input:
    ```java
        String input = "package test;"
        Pointer<TSTree> tree = ts_parser_parse_string(parser, null, Pointer.pointerToCString(input), input.length());
    ```

More examples are available as [test projects](tree-sitter-generate-maven-plugin/src/test/resources/test-project).

## Limitations

- TreeSitter has many functions that pass `struct`s by value. However, BridJ does not support this due to a limitation in the underlying `dyncall` library: https://github.com/nativelibs4java/BridJ/issues/46
- Currently, the native libraries are assumed to be compiled on the `darwin_universal` architecture (MacOS), multi-arch support is still to-do
