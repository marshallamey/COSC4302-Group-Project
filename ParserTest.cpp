#include "Parser.hpp"
#include "Command.hpp"
#include <iostream>

// To execute run the following commands
// $ make ParserTest

// Expected: 1111 111 11111111
int main() {
    // Test 1a: Tokenize space-delimted string
    std::vector<std::string> args1 = 
        tokenize("   hello  world foo      bar baz", ' ');
    std::vector<std::string> expected_args1 {
        "hello", "world", "foo", "bar", "baz"
    };   
    std::cout << (args1 == expected_args1);

    // Test 1b: Tokenize empty string
    std::vector<std::string> args2 = tokenize("", ' ');
    std::cout << args2.empty();
    
    // Test 1c: Tokenize space-only string
    std::vector<std::string> args3 = tokenize("   ", ' ');
    std::cout << args3.empty();

    // Test 1d: Tokenize colon-delimted string
    std::vector<std::string> paths = 
        tokenize("/bin:/sbin:::/usr/bin:::/usr/sbin/::::", ':');
    std::vector<std::string> expected_paths {
        "/bin", "/sbin", "/usr/bin", "/usr/sbin/"
    };
    std::cout << (paths == expected_paths);

    std::cout << ' ';
    
    // Test 2a: Path Resolve for /bin
    std::string echo_path = path_resolver("echo");
    std::cout << (echo_path == "/bin/echo");

    // Test 2b: Path Resolve for /usr/bin
    std::string find_path = path_resolver("find");
    std::cout << (find_path == "/usr/bin/find");
    
    // Test 2c: Path Resolve for slashed command
    std::string ls_path = path_resolver("/bin/ls");
    std::cout << (ls_path == "/bin/ls");
    
    std::cout << ' ';
    
    // Test 3a: Echo Command
    std::string expected_echo_filename { "/bin/echo" };
    std::vector<std::string> expected_echo_args { "echo", "hello", "world" };
    
    Command echo = make_command(" echo  hello   world   ");
    
    std::cout << (echo.get_filename() == expected_echo_filename);
    std::cout << (echo.get_args() == expected_echo_args);

    // Test 3b: Find Command
    std::string expected_find_filename { "/usr/bin/find" };
    std::vector<std::string> expected_find_args { "find", "." };
    
    Command find = make_command("find     .  ");
    
    std::cout << (find.get_filename() == expected_find_filename);
    std::cout << (find.get_args() == expected_find_args);
    

    // Test 3c: Slash Command
    std::string expected_ls_filename { "/bin/ls" };
    std::vector<std::string> expected_ls_args { "/bin/ls", "." };
    
    Command ls = make_command("/bin/ls     .  ");
    
    std::cout << (ls.get_filename() == expected_ls_filename);
    std::cout << (ls.get_args() == expected_ls_args);
    
    // Test 3d: Empty Command
    Command empty = make_command("  ");
    
    std::cout << empty.get_filename().empty();
    std::cout << empty.get_args().empty();

    std::cout << '\n';
}
