#include "Zombie.hpp"

int main()
{
    Zombie *allocated;

    allocated = newZombie("Carlinhos");
    allocated->announce();
    delete allocated;
    allocated = NULL;
    randomChump("JoseCleiton");
    return (0);
}