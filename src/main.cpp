#include <iostream>

#include "Renderer.h"

int main() {
    std::cout << "Starting..." << std::endl;

    Renderer r;
    if(r.init() == 0)
        r.run();

    std::cout << "Ending." << std::endl;
    return 0;
}