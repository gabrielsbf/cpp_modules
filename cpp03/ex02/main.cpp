#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main(void) {
	std::string scavName = "Scav 01";
	std::string clapName = "CLAP 00";
	std::string fragName = "Scavenger D2";
	
	ScavTrap	*scavTrap = new ScavTrap(scavName);
	FragTrap	fragTrap("Frag New");
	ClapTrap	clapTrap(clapName);

	clapTrap.attack(scavName);
	
	scavTrap->attack(clapName);
	fragTrap.takeDamage(FRAG_ATTACK);
	clapTrap.takeDamage(CLAP_ATTACK);
	fragTrap.beRepaired(5000);
	scavTrap->guardGate();
	for (int i = 0; i < 50; i++)
		fragTrap.beRepaired(5000);
	scavTrap->attack(scavTrap->getName());
	scavTrap->guardGate();
	fragTrap.highFivesGuys();
	scavTrap->takeDamage(5000);
	delete scavTrap;
	return (0);
}