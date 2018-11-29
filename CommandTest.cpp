#include "Command.hpp"
#include <iostream>
#include <vector>
#include <string>

// To run test, run the following commands
// $ make CommandTest
// $ ./command-test
// Remember to use CTRL-D exit out of Test 4.

int main() {
    // Test 1: Test output only command
    std::vector<std::string> cat_args {"/bin/cat", "/proc/version"};
    Command cat { cat_args };
    std::cout << (cat.get_args() == cat_args) << '\n';
    cat.execute();
   
    // Test 2: Test output ofenviroment variable
    std::vector<std::string> printenv_args {"/usr/bin/printenv", "PATH"};
    Command printenv { printenv_args };
    std::cout << (printenv.get_args() == printenv_args) << '\n';
    printenv.execute();
   
    // Test 3: Test with multiple parameters
    std::vector<std::string> echo_args {"/bin/echo", "Hello", "World"};
    Command echo { echo_args };
    std::cout << (echo.get_args() == echo_args) << '\n';
    echo.execute();
    
    // Test 4: Test input/output command (CTRL-D to exit)
    std::vector<std::string> grep_args {"/bin/grep", "[aeiou]"};
    Command grep { grep_args };
    std::cout << (grep.get_args() == grep_args) << '\n';
    grep.execute();
    
    // Test 5: Test non-existent command
    std::vector<std::string> mkpokms_args {"/bin/mkpokms"};
    Command mkpokms { mkpokms_args };
    std::cout << (mkpokms.get_args() == mkpokms_args) << '\n';
    try {
       mkpokms.execute();
    } catch (const ExecutionException& e) {
        std::cerr << e.what() << std::endl;
    }   
}
