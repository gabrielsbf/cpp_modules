#include "Zombie.hpp"

int main(void)
{
    int zombieNbr = 10;
    int i = 0;

    Zombie *horde = zombieHorde(zombieNbr, "José");
    while (i < zombieNbr)
    {
        horde[i].announce();
        i++;
    }
    i = 0;
    delete[] horde;
    
}