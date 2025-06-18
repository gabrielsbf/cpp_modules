#include "HumanB.hpp"

HumanB::HumanB(const std::string &h_name, Weapon *h_weapon) : name(h_name), weapon(h_weapon){}

HumanB::HumanB(const std::string &h_name) : name(h_name){}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &h_weapon)
{
    weapon = &h_weapon;
}

void HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}