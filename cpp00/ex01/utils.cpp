#include "utils.hpp"

void    verifyKeyError(void)
{
    if (std::cin.eof())
    {
        std::cout << "\nUnexpected Key Triggered, exiting the program now" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::exit(EXIT_SUCCESS);
    }
}