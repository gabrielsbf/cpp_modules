#include "HumanA.hpp"

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}