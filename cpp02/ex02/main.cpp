#include "includes/Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed c(++Fixed(0));
    std::cout <<"A is: " << a << std::endl;
    std::cout <<"Pre increment operation - A is: " << ++a << std::endl;
    std::cout <<"A is: " << a << std::endl;
    std::cout <<"Post increment operation - A is: " <<  a++ << std::endl;
    std::cout <<"A is: " << a << std::endl;
    std::cout <<"B is: " << b << std::endl;
    std::cout <<"C is: " << ++c << std::endl;
    if (c == a)
        std::cout << "C is equal to A" << std::endl;
    std::cout <<"MAX IS : " << Fixed::max(a, b) << std::endl;
    std::cout <<"MIN IS : " << Fixed::min(a, b) << std::endl;
    return 0;
}