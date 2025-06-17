#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon &h_weapon)
{
    weapon = &h_weapon;
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}