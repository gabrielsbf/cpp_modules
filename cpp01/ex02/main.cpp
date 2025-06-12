#include <string>
#include <iostream>

int main(void)
{
    std::string target = "HI THIS IS BRAIN";
    std::string *stringPTR = &target;
    std::string &stringREF = target;

    std::cout << "   target string memory address: " << &target << std::endl;
    std::cout << "stringPTR string memory address: " << stringPTR << std::endl;
    std::cout << "stringREF string memory address: " << &stringREF << std::endl;

    std::cout << "   target string value: " << target << std::endl;
    std::cout << "stringPTR string value: " << *stringPTR << std::endl;
    std::cout << "stringREF string value: " << stringREF << std::endl;
}