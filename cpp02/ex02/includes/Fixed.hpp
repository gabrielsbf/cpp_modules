#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

#ifndef DEBUG_CONSOLE
#define DEBUG_CONSOLE 0
#endif

class Fixed
{
private:
	static const int _fractional = 8;
	int _raw;

public:
	//Constructors / Destructor
	Fixed();
	Fixed(const int new_raw);
	Fixed(const float new_raw);
	Fixed(const Fixed &copy);
	~Fixed();

	//Operators
		//Attribuition op
	Fixed& operator=(const Fixed &copy);
		//Comparation Operator
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
		//Arithmetic Operations
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
			//Increment and Decrement
	Fixed operator++(int);
	Fixed operator++(void);
	Fixed operator--(int);
	Fixed operator--(void);
	//Public Fun
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int	toInt(void) const;
	float	toFloat(void) const;
	
	//Static Functions
	static Fixed  &max(Fixed &classOne, Fixed &classTwo);
	static Fixed  &min(Fixed &classOne, Fixed &classTwo);
	static Fixed const &max(Fixed const &classOne, Fixed const &classTwo);
	static Fixed const &min(Fixed const &classOne, Fixed const &classTwo);
};

std::ostream& operator<<( std::ostream& os, const Fixed& number );

#endif