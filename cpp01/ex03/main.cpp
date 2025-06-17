#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    std::cout << "HUMAN A" << std::endl;
    
    Weapon club = Weapon("crude");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    std::cout << "---------------------------------" << std::endl;
    std::cout << "HUMAN B" << std::endl;
    
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("now");
    jim.attack();

    
}