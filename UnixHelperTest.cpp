#include "UnixHelper.hpp"
#include <iostream>

int main () {
    std::cout << get_cs_path() << '\n';
    std::cout << get_cwd() << '\n';
}
