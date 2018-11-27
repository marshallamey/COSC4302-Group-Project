#include <string>
#include <vector>
#include <iostream>
#include "Parser.hpp"
#include "UnixHelper.hpp"
#include "Command.hpp"

// To execute run the following commands
// $ g++ -std=c++11 -o parser-test Parser.cpp Parser.hpp ParserTest.cpp UnixHelper.hpp UnixHelper.cpp Command.hpp Command.cpp
// $ ./parser-test

int main() {
    // Test 1a: Tokenize space-delimted string
    std::vector<std::string> args1 = tokenize("   hello  world foo      bar baz", ' ');
    std::vector<std::string> expected_args1 {
        "hello", "world", "foo", "bar", "baz"
    };   
    std::cout << (args1 == expected_args1) << '\n';

    // Test 1b: Tokenize empty string
    std::vector<std::string> args2 = tokenize("", ' ');
    std::vector<std::string> expected_args2 { };   
    std::cout << (args2 == expected_args2) <<'\n';
    
    // Test 1c: Tokenize space-only string
    std::vector<std::string> args3 = tokenize("   ", ' ');
    std::vector<std::string> expected_args3 { };   
    std::cout << (args3 == expected_args3) << '\n';

    // Test 2: Tokenize colon-delimted string
    std::vector<std::string> paths = tokenize("/bin:/sbin:::/usr/bin:::/usr/sbin/::::", ':');
    std::vector<std::string> expected_paths {
        "/bin", "/sbin", "/usr/bin", "/usr/sbin/"
    };
    std::cout << (paths == expected_paths) << '\n';

    // Test 3a: Path Resolve for /bin
    std::string echo_path = path_resolver("echo");
    std::cout << (echo_path == "/bin/echo") << '\n';

    // Test 3b: Path Resolve for /usr/bin
    std::string find_path = path_resolver("find");
    std::cout << (find_path == "/usr/bin/find") << '\n';
    
    // Test 3c: Path Resolve for local script (e.g. not found in any PATH folders)
    std::string myscript_path = path_resolver("myscript");
    std::cout << (myscript_path == (get_cwd() + "/myscript")) << '\n';
    
    // Test 3d: Path Resolve for slashed command
    std::string myscript_path = path_resolver("/bin/ls");
    std::cout << (myscript_path == "/bin/ls") << '\n';
    
    // Test 4a: Echo Command
    Command echo = make_command(" echo  hello   world   ");
    std::vector<std::string> expected_echo_args {
        "/bin/echo", "hello", "world"
    });
    std::cout << (echo.get_args() ==  expected_echo_args) << '\n';
    echo.excecute();

    // Test 4b: Echo Command
    Command find = make_command("find     .  ");
    std::vector<std::string> expected_find_args {
        "/usr/bin/find", "."
    });
    std::cout << (find.get_args() ==  expected_find_args) << '\n';
    find.excecute();
    
    // Test 4c: Local Script Command
    std::string myscript = make_command("myscript");
    std::vector<std::string> expected_myscript_args {
        get_cwd() + "/myscript"
    });
    std::cout << (myscript.get_args() ==  expected_myscript_args) << '\n';
    myscript.excecute();
    
    // Test 4b: Slash Command
    Command ls = make_command("/bin/ls     .  ");
    std::vector<std::string> expected_ls_args {
        "/bin/ls", "."
    });
    std::cout << (ls.get_args() ==  expected_ls_args) << '\n';
    ls.excecute();
}
