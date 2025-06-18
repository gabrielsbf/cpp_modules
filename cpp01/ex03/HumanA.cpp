#include "HumanA.hpp"

HumanA::HumanA(const std::string &h_name, Weapon &h_weapon):name(h_name), weapon(h_weapon){}

HumanA::~HumanA(){};

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}