#include "Parser.hpp"
#include "Command.hpp"
#include <iostream>

void assert_equals(const std::vector<std::string> expected, const std::vector<std::string> actual) {
    if (expected == actual) {
        std::cout << 1;
    } else {
        std::cout << "\n";
        std::cout << "\nExpected:";
        for (auto& item : expected) { 
            std::cout << " \"" << item << "\"";
        }
        std::cout << "\nActual:";
        for (auto& item : actual) { 
            std::cout << " \"" << item << "\"";
        }
        std::cout << "\n";
    }
}


void assert_equals(const std::string expected, const std::string actual) {
    if (expected == actual) {
        std::cout << 1;
    } else {
        std::cout << "\n";
        std::cout << "\nExpected: \"" << expected << "\"";
        std::cout << "\nActual: \"" << actual << "\"";
        std::cout << "\n";
    }
}


// To execute run the following commands
// $ make ParserTest

// Expected: 111111 111 11111111
int main() {
    // Test 1a: Tokenize space-delimted string
    std::vector<std::string> args1 = 
        tokenize("   hello  world\tfoo   \n   bar baz", " \n\t\r");
    std::vector<std::string> expected_args1 {
        "hello", "world", "foo", "bar", "baz"
    };   
    assert_equals(expected_args1, args1);

    // Test 1b: Tokenize empty string
    std::vector<std::string> args2 = tokenize("", " \n\t\r");
    assert_equals({ }, args2);
    
    // Test 1c: Tokenize space-only string
    std::vector<std::string> args3 = tokenize(" \n\t", " \n\t\r");
    assert_equals({ }, args3);
    
    // Test 1d: Tokenize single token string
    std::vector<std::string> args4 = tokenize("foo", " \n\t\r");
    assert_equals({ "foo" }, args4);

    // Test 1e: Tokenize colon-delimted string
    std::vector<std::string> paths = 
        tokenize("/bin:/sbin:::/usr/bin:::/usr/sbin/::::", ":");
    std::vector<std::string> expected_paths {
        "/bin", "/sbin", "/usr/bin", "/usr/sbin/"
    };
    assert_equals(expected_paths, paths);

    std::cout << ' ';
    
    // Test 2a: Path Resolve for /bin
    std::string echo_path = path_resolver("echo");
    assert_equals("/bin/echo", echo_path);

    // Test 2b: Path Resolve for /usr/bin
    std::string find_path = path_resolver("find");
    assert_equals("/usr/bin/find", find_path);
    
    // Test 2c: Path Resolve for slashed command
    std::string ls_path = path_resolver("/bin/ls");
    assert_equals("/bin/ls", ls_path);
    
    std::cout << ' ';
    
    // Test 3a: Echo Command
    Command echo = make_command(" echo  hello   world   ");
    
    assert_equals("/bin/echo", echo.get_filename());
    assert_equals({ "echo", "hello", "world" }, echo.get_args());

    // Test 3b: Find Command
    Command find = make_command("find     .  ");
    
    assert_equals("/usr/bin/find", find.get_filename());
    assert_equals({ "find", "." }, find.get_args());
    

    // Test 3c: Slash Command
    Command ls = make_command("/bin/ls     .  ");
    
    assert_equals("/bin/ls", ls.get_filename());
    assert_equals({ "/bin/ls", "." }, ls.get_args());
    
    // Test 3d: Empty Command
    Command empty = make_command("  ");
    
    assert_equals("", empty.get_filename());
    assert_equals({ }, empty.get_args());

    std::cout << std::endl;
}
