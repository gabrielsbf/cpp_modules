#ifndef HUMAN_B
#define HUMAN_B
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB(const std::string &h_name, Weapon *h_weapon):name(h_name), weapon(h_weapon){};
    HumanB(const std::string &h_name):name(h_name){};
    ~HumanB(){};

    void    setWeapon(Weapon &h_weapon);
    void    attack(void);
};
#endif