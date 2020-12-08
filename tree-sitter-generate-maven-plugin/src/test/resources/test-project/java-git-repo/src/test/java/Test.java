import com.github.mpsijm.javatreesitter.*;
import com.github.mpsijm.javatreesitter.java.*;
import junit.framework.*;
import org.bridj.*;

import static com.github.mpsijm.javatreesitter.JavaTreeSitterLibrary.*;

public class Test extends TestCase {
    public void test() {
        Pointer<TSLanguage> javaLanguage = TreeSitterJavaLibrary.tree_sitter_java();

        Pointer<TSParser> parser = ts_parser_new();
        ts_parser_set_language(parser, javaLanguage);

        String input1 = "package test;";

        Pointer<TSTree> previousTree =
                ts_parser_parse_string(parser, null, Pointer.pointerToCString(input1), input1.length());
        assertNotNull(previousTree);

        for (int i = 1; i <= 10; i++) {
            StringBuilder sb = new StringBuilder();
            sb.append(input1);
            for (int j = 0; j < i; j++) {
                sb.append(".test");
            }
            sb.append(";");
            String input2 = sb.toString();

            Pointer<TSInputEdit> edit = Pointer.allocate(TSInputEdit.class);
            edit.get().start_byte(8).old_end_byte(8).new_end_byte(8 + 5 * i);
            Pointer<TSTree> copyOfPrevious = ts_tree_copy(previousTree);
            ts_tree_edit(copyOfPrevious, edit);

            Pointer<TSTree> newTree =
                    ts_parser_parse_string(parser, copyOfPrevious, Pointer.pointerToCString(input2), input2.length());
            assertNotNull(newTree);
        }
    }
}
