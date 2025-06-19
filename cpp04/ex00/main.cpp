#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"
int main()
{
    Cat *meow = new Cat;
    Animal generic("Dragon");
    Dog doggo;
    WrongAnimal wrongAnimal("Strange Beast");
    WrongCat wrongCat;

    std::cout << "Cat says: "; 
    meow->makeSound();
    std::cout << "Generic Animal says: ";
    generic.makeSound();
    std::cout << "Dog says: ";
    doggo.makeSound();

    std::cout << "Cat type has to be: " << meow->getType() << std::endl;
    std::cout << "Dog type has to be: " << doggo.getType() << std::endl;
    std::cout << "Animal type has to be: " << generic.getType() << std::endl;
    
    std::cout << "WRONG ANIMAL [WITHOUT THE VIRTUAL KEY]" << std::endl;
    std::cout << "[WRONG]Cat says: "; 
    wrongCat.makeSound();
    std::cout << "[WRONG]Generic Animal says: ";
    wrongAnimal.makeSound();
    std::cout << std::endl << "DESTRUCTORS" << std::endl;
    delete meow;
}