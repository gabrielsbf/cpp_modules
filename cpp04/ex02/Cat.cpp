#include "includes/Cat.hpp"

Cat::Cat(void): Animal(), _brain(new Brain)
{
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
    std::cout << "******************************" << std::endl;
}

Cat::Cat(Cat const & src): Animal(), _brain(NULL)
{
    *this = src;
    std::cout << "Cat Copy constructor called" << std::endl;
    std::cout << "******************************" << std::endl;
}

Cat & Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		this->type = src.type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain);
	}
    std::cout << "Cat Copy assignment operator called" << std::endl;
    std::cout << "******************************" << std::endl;
    return *this;
}

Cat::~Cat(void)
{
    if (this->_brain != NULL)
        delete this->_brain;
    std::cout << "Cat Default destructor called" << std::endl;
}

Brain* Cat::getBrain()
{
    return (this->_brain);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow meow!" << std::endl;
}