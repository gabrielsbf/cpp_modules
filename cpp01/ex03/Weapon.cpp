#include "Weapon.hpp"

const std::string Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string new_type)
{
    this->type = new_type;
}