#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string ZombieName)
{
    name = ZombieName;
}