#include "includes/Fixed.hpp"

//Constructors & Destructor

Fixed::Fixed(): _raw(0)
{
    if (DEBUG_CONSOLE)
        std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy): _raw(copy._raw)
{
    if (DEBUG_CONSOLE)
        std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int new_raw): _raw(new_raw << _fractional)
{
    if (DEBUG_CONSOLE)
        std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float new_raw): _raw(roundf(new_raw * (1 << _fractional)))
{
    if (DEBUG_CONSOLE)
        std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    if (DEBUG_CONSOLE)
        std::cout << "destructor called" << std::endl;
}

//Functions


int Fixed::getRawBits(void) const
{
    if (DEBUG_CONSOLE)
        std::cout << "getRawBits member function called" << std::endl;
    return(_raw);
}

void    Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
    if (DEBUG_CONSOLE)
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
    //Comparison and Arithmetics Operator
bool Fixed::operator>(const Fixed &other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
        return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
            return (this->toFloat() / other.toFloat());
}
        //Increment and Decrement
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_raw += 1;
    return (tmp);
}

Fixed Fixed::operator++(void)
{
    this->_raw += 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_raw -= 1;
    return (tmp);
}

Fixed Fixed::operator--(void)
{
    this->_raw -= 1;
    return (*this);
}

    //Attribuition Operator
Fixed &Fixed::operator=(const Fixed& copy)
{
    if (this != &copy)
    {
        _raw = copy._raw;
    }
    if (DEBUG_CONSOLE)
        std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed &Fixed::max(Fixed &classOne, Fixed &classTwo)
{
    if (DEBUG_CONSOLE)
        std::cout << "Running Max" << std::endl;
    if (classOne >= classTwo)
        return (classOne);
    return (classTwo);
}

Fixed &Fixed::min(Fixed &classOne, Fixed &classTwo)
{
    if (DEBUG_CONSOLE)
        std::cout << "Running Min" << std::endl;
    if (classOne <= classTwo)
        return (classOne);
    return (classTwo);
}

Fixed const &Fixed::max(const Fixed &classOne, const Fixed &classTwo)
{
    if (DEBUG_CONSOLE)
        std::cout << "Running Max Const" << std::endl;
    if (classOne >= classTwo)
        return (classOne);
    return (classTwo);
}

Fixed const &Fixed::min(Fixed const & classOne, Fixed const & classTwo)
{
    if (DEBUG_CONSOLE)
        std::cout << "Running Min Const" << std::endl;
    if (classOne <= classTwo)
        return (classOne);
    return (classTwo);
}


    //Display Overload
std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
    os << number.toFloat();
    return (os);
}