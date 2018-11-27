#ifndef UNIX_HELPER_H
#define UNIX_HELPER_H

#include <string>

// Get CS Path for Path Resolution
// This is a colon seperated list of directories
std::string get_cs_path();

// Get Current Working Directory
std::string get_cwd();

#endif // UNIX_HELPER_H
