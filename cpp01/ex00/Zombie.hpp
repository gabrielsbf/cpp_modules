#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string ZombieName):name(ZombieName){};
        ~Zombie(){
                std::cout << "Zombie " << name << " was destroyed" << std::endl;
        };
        void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif
