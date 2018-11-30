#include <iostream>

#include "System.h"

int main() {
    System sys{};

    std::cout << "Hello, World!" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    sys.populate();
    sys.run();

    std::cout << "!~~## Obrigado por usar o sistema de gerenciamento de frota Poldinho Pikanelson! ##~~!" << std::endl;

    return 0;
}