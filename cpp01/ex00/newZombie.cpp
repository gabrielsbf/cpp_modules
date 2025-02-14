#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    std::cout << "Creating Zombie: " << name << " with method NewZombie" << std::endl;
    return (new Zombie(name));
}