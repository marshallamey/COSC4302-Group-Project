#include "Command.hpp"
#include <iostream>

// To run test, run the following commands
// $ make CommandTest
// Remember to use CTRL-D exit out of Test 4.

int main() {
    try {
        // Test 1: Test no-operation command
        Command no_op { };
    
        std::cout << no_op.get_filename().empty();
        std::cout << no_op.get_args().empty();
        std::cout << '\n';
    
        no_op.execute();
        
        // Test 1: Test output only command
        std::string cat_filename { "/bin/cat" };
        std::vector<std::string> cat_args { "cat", "/proc/version" };
    
        Command cat { cat_filename, cat_args };
    
        std::cout << (cat.get_filename() == cat_filename);
        std::cout << (cat.get_args() == cat_args);
        std::cout << '\n';
    
        cat.execute();
   
    
        // Test 2: Test output of enviroment variable
        std::string printenv_filename { "/usr/bin/printenv" };
        std::vector<std::string> printenv_args { "printenv", "PATH" };
    
        Command printenv { printenv_filename, printenv_args };
    
        std::cout << (printenv.get_filename() == printenv_filename);
        std::cout << (printenv.get_args() == printenv_args);
        std::cout << '\n';
    
        printenv.execute();
   
    
        // Test 3: Test with multiple parameters
        std::string echo_filename { "/bin/echo" };
        std::vector<std::string> echo_args { "/bin/echo", "Hello", "World" };
    
        Command echo { echo_filename, echo_args };
    
        std::cout << (echo.get_filename() == echo_filename);
        std::cout << (echo.get_args() == echo_args);
        std::cout << '\n';
    
        echo.execute();

    
        // Test 4: Test input/output command (CTRL-D to exit)
        std::string grep_filename { "/bin/grep" };
        std::vector<std::string> grep_args { "grep", "[aeiou]" };
    
        Command grep { grep_filename, grep_args };
    
        std::cout << (grep.get_filename() == grep_filename);
        std::cout << (grep.get_args() == grep_args);
        std::cout << '\n';
    
        grep.execute();
    
        // Test 5: Test non-existent command
        std::string mkpokms_filename { "/bin/mkpokms" };
        std::vector<std::string> mkpokms_args { "mkpokms" };
        Command mkpokms { mkpokms_filename, mkpokms_args };
        
        std::cout << (mkpokms.get_filename() == mkpokms_filename);
        std::cout << (mkpokms.get_args() == mkpokms_args);
        std::cout << '\n';
    
        mkpokms.execute();   
    } catch (const ExecutionException& e) {
        std::cerr << e.what() << std::endl;
    }
}
