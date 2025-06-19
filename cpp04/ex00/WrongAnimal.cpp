#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Wrong Animal")
{
	std::cout <<  "WrongAnimal default constructor called."  << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout <<  "WrongAnimal copy constructor called."  << std::endl;
	*this = src;
	return ;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type)
{
	std::cout <<  "WrongAnimal type constructor called."  << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout <<  "WrongAnimal destructor called."  << std::endl;
    std::cout << "******************************" << std::endl;
	return ;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout <<  "WrongAnimal operator constructor called."  << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const &	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->_type
		<< ": * Wrong Animal Sounds like (?)..."  << std::endl;
	return ;
}