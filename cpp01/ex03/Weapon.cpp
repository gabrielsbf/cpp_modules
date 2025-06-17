#include "Weapon.hpp"

const std::string &Weapon::getType(void)
{
    return (type);
}

void Weapon::setType(const std::string &new_type)
{
    type = new_type;
}