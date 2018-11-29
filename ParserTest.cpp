#include "Parser.hpp"
#include "UnixHelper.hpp"
#include "Command.hpp"
#include <iostream>

// To execute run the following commands
// $ g++ -std=c++11 -o parser-test Parser.cpp Parser.hpp ParserTest.cpp UnixHelper.hpp UnixHelper.cpp Command.hpp Command.cpp
// $ ./parser-test

// Expected: 1111111111111
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
    std::vector<std::string> expected_args2 { };   
    std::cout << (args2 == expected_args2);
    
    // Test 1c: Tokenize space-only string
    std::vector<std::string> args3 = tokenize("   ", ' ');
    std::vector<std::string> expected_args3 { };   
    std::cout << (args3 == expected_args3);

    // Test 2: Tokenize colon-delimted string
    std::vector<std::string> paths = 
        tokenize("/bin:/sbin:::/usr/bin:::/usr/sbin/::::", ':');
    std::vector<std::string> expected_paths {
        "/bin", "/sbin", "/usr/bin", "/usr/sbin/"
    };
    std::cout << (paths == expected_paths);

    // Test 3a: Path Resolve for /bin
    std::string echo_path = path_resolver("echo");
    std::cout << (echo_path == "/bin/echo");

    // Test 3b: Path Resolve for /usr/bin
    std::string find_path = path_resolver("find");
    std::cout << (find_path == "/usr/bin/find");
    
    // Test 3c: Path Resolve for local script
    std::string myscript_path = path_resolver("myscript");
    std::cout << (myscript_path == (get_cwd() + "/myscript"));
    
    // Test 3d: Path Resolve for slashed command
    std::string ls_path = path_resolver("/bin/ls");
    std::cout << (ls_path == "/bin/ls");
    
    // Test 4a: Echo Command
    Command echo = make_command(" echo  hello   world   ");
    std::vector<std::string> expected_echo_args {
        "/bin/echo", "hello", "world"
    };
    std::cout << (echo.get_args() == expected_echo_args);

    // Test 4b: Find Command
    Command find = make_command("find     .  ");
    std::vector<std::string> expected_find_args {
        "/usr/bin/find", "."
    };
    std::cout << (find.get_args() == expected_find_args);
    
    // Test 4c: Local Script Command
    Command myscript = make_command("myscript");
    std::vector<std::string> expected_myscript_args {
        get_cwd() + "/myscript"
    };
    std::cout << (myscript.get_args() == expected_myscript_args);
    
    // Test 4d: Slash Command
    Command ls = make_command("/bin/ls     .  ");
    std::vector<std::string> expected_ls_args {
        "/bin/ls", "."
    };
    std::cout << (ls.get_args() == expected_ls_args);
    
    // Test 4e: Empty Command
    Command empty = make_command("  ");
    std::vector<std::string> expected_empty_args { };
    std::cout << (empty.get_args() == expected_empty_args);
    
    std::cout << '\n';
}
