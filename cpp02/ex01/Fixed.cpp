#include "includes/Fixed.hpp"

//Constructors & Destructor

Fixed::Fixed(): _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy): _raw(copy._raw)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int new_raw): _raw(new_raw << _fractional)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float new_raw): _raw(roundf(new_raw * (1 << _fractional)))
{
    std::cout << "Float constructor called" << std::endl;
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
    std::cout << "destructor called" << std::endl;
}

//Functions


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

int  Fixed::toInt(void) const
{
    return (_raw >> _fractional);
}

float   Fixed::toFloat(void) const
{
    return ((float)_raw / (1 << _fractional));
}

//Operator Overload

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
    os << number.toFloat();
    return (os);
}