#include "chap01.hpp"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Message say_hello("Hello, CMake World!");
    std::cout << say_hello << std::endl;

    return EXIT_SUCCESS;
}
