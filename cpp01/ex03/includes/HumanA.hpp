#ifndef HUMAN_A
#define HUMAN_A
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon;

public:
    HumanA(const std::string &h_name, Weapon &h_weapon);
    ~HumanA();
    void attack(void);
};

#endif