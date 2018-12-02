#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <cstdlib>
#include "Parser.hpp"
#include "Command.hpp"

std::vector<std::string> tokenize(const std::string& document, const std::string& delimiters) {
    std::vector<std::string> tokens;
    
    // Skip beginning delimiters
    std::size_t start = document.find_first_not_of(delimiters), end = 0;
    
    //Find tokens
    while ((end = document.find_first_of(delimiters, start)) != std::string::npos) {
        tokens.push_back(document.substr(start, end - start));
        start = document.find_first_not_of(delimiters, end);
    }
    
    // If there is one last token, push to tokens
    if (start != std::string::npos) tokens.push_back(document.substr(start)); 

    return tokens;
}

std::string path_resolver(const std::string& program_name) {
    // If path starts with a slash, return it as it is
    if (program_name.find("/") != std::string::npos) return program_name;

    // Else search the directories in $PATH environment variable
    std::vector<std::string> paths = tokenize(std::string(getenv("PATH")), ":");
    for(int i = 0; i < int(paths.size()); i++) {
        std::string path = paths[i] + "/" + program_name;
        if( access( path.c_str(), F_OK) == 0 ) return path;
    }
    
    // Else return path not found 
    std::cout << program_name << ": Path not found\n";
    return program_name; 
}

Command make_command(const std::string& document) {
    // Parse document to retrieve list of args
    std::vector<std::string> args = tokenize(document, " \n\t\r");
    
    // If no args, return empty Command
    if( args.size() == 0 ) return Command();

    // Else return Command with args
    std::string filename = path_resolver(args[0]);
    return Command(filename, args);
}
