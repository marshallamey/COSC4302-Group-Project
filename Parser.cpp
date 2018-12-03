#include "Parser.hpp"
#include "UnixHelper.hpp"
#include "Command.hpp"
#include <cstdlib>


// Helper Function: Get PATH from ENV or CONFIGURATION
std::string get_path() {
    std::string env_path {std::getenv("PATH")};
    return env_path.empty() 
        ? get_cs_path() 
        : env_path;
}


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
    if (program_name.find('/') != std::string::npos) return program_name;

    // Else search the directories in $PATH environment variable
    std::vector<std::string> paths = tokenize(get_path(), ":");
    for(const std::string& directory : paths) {
        std::string path = directory + "/" + program_name;
        if( exists(path) && executable(path) ) return path;
    }
    
    // Else return path not found 
    return program_name; 
}

Command make_command(const std::string& document) {
    // Parse document to retrieve list of args
    std::vector<std::string> args = tokenize(document, " \n\t\r");
    
    // If no args, return empty Command
    if( args.empty() ) return Command();

    // Else return Command with args
    std::string filename = path_resolver(args.front());
    return Command(filename, args);
}
