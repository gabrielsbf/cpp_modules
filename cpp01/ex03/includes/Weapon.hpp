#include <string>
#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string weapon_type):type(weapon_type){};
    Weapon(){};
    ~Weapon(){};
    const std::string getType(void);
    void setType(std::string new_type);
};
