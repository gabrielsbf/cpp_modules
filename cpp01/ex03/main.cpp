#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    std::cout << "HUMAN A" << std::endl;
    
    Weapon club = Weapon("Wooden Club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("Gigantic Club");
    bob.attack();
    std::cout << "---------------------------------" << std::endl;
    std::cout << "HUMAN B" << std::endl;
    
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("Spiked Club");
    jim.attack();

    
}