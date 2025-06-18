#include "includes/Dog.hpp"

Dog::Dog(void): Animal()
{
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(Dog const & src): Animal()
{
    *this = src;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    if (this != &src)
    {
        type = src.type;
    }
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(void)
{
    std::cout << "Dog Default destructor called" << std::endl;
}

void Dog::makeSound(void)
{
    std::cout << "Bark Bark!" << std::endl;
}