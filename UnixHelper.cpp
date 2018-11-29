#include "UnixHelper.hpp"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

std::string get_cs_path() {
    // Allocate a buffer
    size_t n = confstr(_CS_PATH, nullptr, 0);
    char* buffer = new char[n];

    // Copy CS_PATH to Buffer, then to string
    confstr(_CS_PATH, buffer, n);
    std::string cs_path { buffer };
    
    // Deallocate and return string
    delete buffer;
    return cs_path;
}

std::string get_cwd() {
    // Copy cwd to Buffer
    char buffer[PATH_MAX];
    getcwd(buffer, PATH_MAX);
    return std::string { buffer };
}

bool exists(const std::string& path) {
    // Checks POSIX Access Flags if a file exists
    return access(path.c_str(), F_OK) == 0;
}

bool executable(const std::string& path) {
    // Checks POSIX Access Flags if a file executable
    return access(path.c_str(), X_OK) == 0;
}

