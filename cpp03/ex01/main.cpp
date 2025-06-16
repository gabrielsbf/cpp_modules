#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int	main(void) {
	std::string scavTrapName = "Scav 01";
	std::string clapTrapName = "CLAP 00";

	ScavTrap	*scavTrap = new ScavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	clapTrap.attack(scavTrapName);
	scavTrap->attack(clapTrapName);
	scavTrap->takeDamage(SCAV_ATTACK);
	clapTrap.takeDamage(CLAP_ATTACK);
	clapTrap.beRepaired(5000);
	scavTrap->guardGate();
	for (int i = 0; i < 50; i++)
		scavTrap->beRepaired(5000);
	scavTrap->attack(scavTrapName);
	scavTrap->guardGate();
	scavTrap->takeDamage(5000);
	delete scavTrap;
	return (0);
}