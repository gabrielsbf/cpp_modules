#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon_type):type(weapon_type){}

Weapon::Weapon(){}

Weapon::~Weapon(){}
const std::string &Weapon::getType(void)
{
    return (type);
}

void Weapon::setType(const std::string &new_type)
{
    type = new_type;
}