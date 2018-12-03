// Author: Kishan Patel
// Instructor: Bo Sun
// COSC 4302: Operating Systems
// Unix Helper Component - Test

#include "UnixHelper.hpp"
#include <iostream>

// To run test, run the following commands
// $ make UnixHelperTest

int main () {
    std::cout << get_cs_path() << '\n';       // Expected: /bin:/usr/bin
    std::cout << get_cwd() << '\n';           // Expected: /home/username/workspace
    std::cout << exists("/notafile");         // Expected: 0
    std::cout << exists("/proc/version");     // Expected: 1
    std::cout << executable("/proc/version"); // Expected: 0
    std::cout << executable("/bin/echo");     // Expected: 1
    std::cout << '\n';
}
