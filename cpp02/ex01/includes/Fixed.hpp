#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>
class Fixed
{
private:
	static const int _fractional = 8;
	int _raw;

public:
	Fixed();
	Fixed(const int new_raw);
	Fixed(const float new_raw);
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed& copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int	toInt(void) const;
	float	toFloat(void) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed& number );

#endif