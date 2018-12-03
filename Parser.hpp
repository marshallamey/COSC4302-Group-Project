// Author: Alexander Macey, Marshall Amey, & Kishan Patel
// Instructor: Bo Sun
// COSC 4302: Operating Systems
// Parser Component - Header

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "Command.hpp"

std::vector<std::string> tokenize(const std::string& document, const std::string& delimiters);

std::string path_resolver(const std::string& program_name);

Command make_command(const std::string& document);

#endif // PARSER_H
