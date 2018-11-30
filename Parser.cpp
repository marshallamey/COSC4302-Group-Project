#include "Parser.hpp"

// This is a stubbed version of the to be implemented Parser.cpp source file. 

std::vector<std::string> tokenize(const std::string& document, char delimiter) {
    return std::vector<std::string> { }; 
}

std::string path_resolver(const std::string& program_name) {
    return std::string { };
}

Command make_command(const std::string& document) {
    return Command {
        "/bin/echo", {"echo", "hello", "world"}
    };
}
