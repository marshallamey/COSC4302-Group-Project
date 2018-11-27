#include <string>
#include <vector>
#include <iostream>
#include "Parser.hpp"
#include "UnixHelper.hpp"

// To execute run the following commands
// $ gcc -std=c++11 -o parser-test Parser.cpp Parser.hpp ParserTest.cpp UnixHelper.hpp UnixHelper.cpp Command.hpp Command.cpp
// $ ./parser-test

int main() {
    // Test 1a: Tokenize space-delimted string
    std::vector<std::string> args = tokenize("   hello  world foo      bar baz", ' ');
    std::vector<std::string> expected_args {
        "hello", "world", "foo", "bar", "baz"
    };   
    std::cout << args == expected_args;

    // Test 1b: Tokenize empty string
    std::vector<std::string> args = tokenize("", ' ');
    std::vector<std::string> expected_args { };   
    std::cout << args == expected_args;
    
    // Test 1c: Tokenize space-only string
    std::vector<std::string> args = tokenize("   ", ' ');
    std::vector<std::string> expected_args { };   
    std::cout << args == expected_args;

    // Test 2: Tokenize colon-delimted string
    std::vector<std::string> paths = tokenize("/bin:/sbin:::/usr/bin:::/usr/sbin/::::", ':');
    std::vector<std::string> expected_paths {
        "/bin", "/sbin", "/usr/bin", "/usr/sbin/"
    };
    std::cout << paths == expected_paths;

    // Test 3a: Path Resolve for /bin
    std::string echo_path = path_resolver("echo");
    std::cout << echo_path == "/bin/echo";

    // Test 3b: Path Resolve for /usr/bin
    std::string find_path = path_resolver("find");
    std::cout << find_path == "/usr/bin/find";
    
    // Test 3b: Path Resolve for local script (e.g. not found in any PATH folders)
    std::string find_path = path_resolver("myscript");
    std::cout << find_path == (get_cwd() + "/myscript");
}
