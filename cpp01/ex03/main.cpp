#include "HumanA.hpp"

int main(void)
{
    Weapon weapon;
    weapon.setType("Axe");

    HumanA bob("Bob", weapon);
    bob.attack();
    weapon.setType("Sword");
    bob.attack();
}