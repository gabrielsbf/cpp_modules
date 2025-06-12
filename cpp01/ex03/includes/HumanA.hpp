#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon weapon;

public:
    HumanA(std::string h_name, Weapon h_weapon):name(h_name), weapon(h_weapon){};
    ~HumanA(){};
    void attack(void);
};

void    HumanA::attack(void)
{
    std::cout << this->name << "attacks with their " << this->weapon.getType() << std::endl;
}