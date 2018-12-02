#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Parser.hpp"
#include "Command.hpp"


std::vector<std::string> tokenize(const std::string& document, char delimiter) {
    std::stringstream ss(document);
    std::string token;
    std::vector<std::string> tokens;
    
    while( getline(ss, token, delimiter) ) tokens.push_back(token);
    return tokens; 
}

std::string path_resolver(const std::string& program_name) {

    // If path starts with a slash, return it as it is
    if (program_name.at(0) == '/') return program_name;

    // Else search the directories in $PATH environment variable
    std::vector<std::string> paths = tokenize(string(getenv("PATH")), ':');
    return std::string { };
    
    // Else if $PATH not defined, search the directories in CS_PATH config variable
 
    // Else throw exception  
}

Command make_command(const std::string& document) {

    // Parse document to retrieve list of args
    std::vector<std::string> args = tokenize(document, ' \n\t\r');
    
    // Find the path for the file
    std::string filename = path_resolver(args[0]);
    
    // Return a command
    return Command(filename, args);
}
