#include "Zombie.hpp"

void randomChump(std::string name)
{
    std::cout << "Creating Zombie: " << name << " with method randomChump" << std::endl;
    Zombie new_zombie(name);
    new_zombie.announce();
}