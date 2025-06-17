#ifndef WEAPON
#define WEAPON

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon(const std::string &weapon_type):type(weapon_type){};
    Weapon(){};
    ~Weapon(){};
    const std::string& getType(void);
    void setType(const std::string &new_type);
};

#endif