#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
private:
	static const int _fractional = 8;
	int _raw;

public:
	Fixed();
	// Fixed()
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed& copy);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif