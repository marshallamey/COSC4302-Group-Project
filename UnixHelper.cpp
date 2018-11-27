#include "UnixHelper.hpp"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

std::string get_cs_path() {
    size_t n = confstr(_CS_PATH, nullptr, 0);
    char* buffer = new char[n];
    confstr(_CS_PATH, buffer, n);
    std::string cs_path { buffer };
    delete buffer;
    return cs_path;
}

std::string get_cwd() {
   char buffer[PATH_MAX];
   getcwd(buffer, PATH_MAX);
   return std::string { buffer };
}
