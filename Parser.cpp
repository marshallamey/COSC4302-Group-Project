#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Parser.hpp"
#include "Command.hpp"


std::vector<std::string> tokenize(const std::string& document, const std::string& delimiters) {
    std::vector<std::string> tokens;
    std::size_t start = document.find_first_not_of(delimiters), end = 0;
    //std::cout << "START: " << start <<"\n";
    while ((end = document.find_first_of(delimiters, start)) != std::string::npos) {
        tokens.push_back(document.substr(start, end - start));
        start = document.find_first_not_of(delimiters, end);
    }

    if (start != std::string::npos) {
        tokens.push_back(document.substr(start));
    }  

    return tokens; 
}

std::string path_resolver(const std::string& program_name) {

    // **Kishan Patel: Consider using std::string::find method instead of std::string::at in this case
    //               : https://en.cppreference.com/w/cpp/string/basic_string/find
    // If path starts with a slash, return it as it is
    if (program_name.at(0) == '/') return program_name;

    // **Kishan Patel: Also your going need to include the header file that std::getenv is defined in. <cstdlib>
    //               : How will you determine if $PATH defined or not? 
    //               : https://en.cppreference.com/w/cpp/utility/program/getenv
    //               : chars like ':' do not implictly convert to std::string, but char* do! (tip: getenv returns a char*)
    // Else search the directories in $PATH environment variable
    std::vector<std::string> paths = tokenize(getenv("PATH"), ":");
    return std::string { };
    
    // Else if $PATH not defined, search the directories in CS_PATH config variable
 
    // **Kishan Patel: Ill-advised, In C++, one should air on the side of caution when 
    //               : throwing an exception for many, many reasons. Just return the 
    //               : an unaltered program_name if you can't resolve a path. If their
    //               : is a problem, I'll throw the exception.
    // Else throw exception  
}

Command make_command(const std::string& document) {
    
    // **Kishan Patel: char type are noted with '' and my only contain one character
    //               : string^ type are noted with "" and may contain zero or more characters
    //               : I'll fix it for you since I need update the test and header files 
    // Parse document to retrieve list of args
    std::vector<std::string> args = tokenize(document, " \n\t\r");
    
    // **Kishan Patel: Mostly correct, but consider what would happen if args was size zero,
    //               : you may want look at ParserTest.cpp and CommandTest.cpp
    // Find the path for the file
    std::string filename = path_resolver(args[0]);
    
    // Return a command
    return Command(filename, args);
}
