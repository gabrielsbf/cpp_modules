#include "includes/Cat.hpp"

Cat::Cat(void): Animal()
{
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
    std::cout << "******************************" << std::endl;
}

Cat::Cat(Cat const & src): Animal()
{
    *this = src;
    std::cout << "Cat Copy constructor called" << std::endl;
    std::cout << "******************************" << std::endl;
}

Cat & Cat::operator=(const Cat& src)
{
    if (this != &src)
    {
        type = src.type;
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    std::cout << "******************************" << std::endl;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << "Cat Default destructor called" << std::endl;
}

void Cat::makeSound(void)
{
    std::cout << "Meow meow!" << std::endl;
}