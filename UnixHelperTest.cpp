#include "UnixHelper.hpp"
#include <iostream>

// To run test, run the following commands
// $ gcc -std=c++11 -o unix-test UnixHelper.hpp UnixHelper.cpp UnixHelperTest.cpp
// $ ./unix-test

int main () {
    std::cout << get_cs_path() << '\n';
    std::cout << get_cwd() << '\n';
}
