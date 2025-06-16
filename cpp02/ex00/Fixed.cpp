#include "includes/Fixed.hpp"

Fixed::Fixed(): _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy): _raw(copy._raw)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this != &copy)
    {
        _raw = copy._raw;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(_raw);
}

void    Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
    std::cout << "setRawBits member function called: new value: " << this->_raw << std::endl;
}

