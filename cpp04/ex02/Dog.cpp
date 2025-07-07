#include "includes/Dog.hpp"

Dog::Dog(void): Animal(), _brain(new Brain)
{
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
    std::cout << "******************************" << std::endl;
}

Dog::Dog(Dog const & src): Animal(), _brain(NULL)
{
    *this = src;
    std::cout << "Dog Copy constructor called" << std::endl;
    std::cout << "******************************" << std::endl;
}

Dog & Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		this->type = src.type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain);
	}
    std::cout << "Dog Copy assignment operator called" << std::endl;
    std::cout << "******************************" << std::endl;
    return *this;
}

Dog::~Dog(void)
{
    if (this->_brain != NULL)
        delete this->_brain;
    std::cout << "Dog Default destructor called" << std::endl;
}

Brain *Dog::getBrain()
{
    return (this->_brain);
}


void Dog::makeSound(void) const
{
    std::cout << "Bark Bark!" << std::endl;
}