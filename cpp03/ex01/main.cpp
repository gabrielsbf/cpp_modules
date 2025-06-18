#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int	main(void) {
	std::string scavName01 = "Scav 01";
	std::string clapTrapName = "CLAP 00";
	std::string scavName02 = "Scavenger D2";
	
	ScavTrap	*scavTrap = new ScavTrap(scavName01);
	ScavTrap	scav02 = *scavTrap;
	scav02.setName("NEW SCAV COPY");
	ClapTrap	clapTrap(clapTrapName);

	clapTrap.attack(scavName01);
	
	scavTrap->attack(clapTrapName);
	scav02.takeDamage(SCAV_ATTACK);
	clapTrap.takeDamage(CLAP_ATTACK);
	clapTrap.beRepaired(5000);
	scavTrap->guardGate();
	for (int i = 0; i < 50; i++)
		scavTrap->beRepaired(5000);
	scavTrap->attack(scavTrap->getName());
	scavTrap->guardGate();
	scavTrap->takeDamage(5000);
	delete scavTrap;
	return (0);
}