import com.github.mpsijm.javatreesitter.*;
import com.github.mpsijm.javatreesitter.toy.*;
import junit.framework.*;
import org.bridj.*;

import static com.github.mpsijm.javatreesitter.JavaTreeSitterLibrary.*;

public class Test extends TestCase {
    public void test() {
        Pointer<TSLanguage> javaLanguage = TreeSitterToyLibrary.tree_sitter_toy();

        Pointer<TSParser> parser = ts_parser_new();
        ts_parser_set_language(parser, javaLanguage);

        String input = "if 42 a = 3 else b = 4";

        Pointer<TSTree> tree = ts_parser_parse_string(parser, null, Pointer.pointerToCString(input), input.length());
        assertNotNull(tree);
    }
}
