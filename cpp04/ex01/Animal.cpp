#include "includes/Animal.hpp"

Animal::Animal(): type("default")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string an_type): type(an_type)
{
    std::cout << "Animal Default constructor called" << std::endl;
}


Animal::Animal(const Animal &copy): type(copy.type)
{
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
    if (this != &copy)
    {
        type = copy.type;
    }
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Default destructor called" << std::endl;
    std::cout << "******************************" << std::endl;
}

std::string Animal::getType(void)
{
    return (this->type);
}

void Animal::makeSound(void)
{
    std::cout << "[Sounds Like a Generic Animal]" << std::endl;
}