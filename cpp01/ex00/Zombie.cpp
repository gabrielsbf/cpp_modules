#include "Zombie.hpp"

Zombie::Zombie(std::string ZombieName):name(ZombieName){}

Zombie::~Zombie(){
    
        std::cout << "Zombie " << name << " was destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}