// Author: Alexander Macey, Marshall Amey, & Kishan Patel
// Instructor: Bo Sun
// COSC 4302: Operating Systems
// Unix Helper Component - Header

#ifndef UNIX_HELPER_H
#define UNIX_HELPER_H

#include <string>

// Retreive the confstr(_CS_PATH), a list of directories containing system-level POSIX programs
std::string get_cs_path();

// Retreive the current working directory
std::string get_cwd();

// Test if the file at the given path exists
bool exists(const std::string& path);

// Test if the file at the given path is executable.
bool executable(const std::string& path);

#endif // UNIX_HELPER_H
