
#include "ClapTrap.hpp"
#include <string>

int	main(void) {
	ClapTrap	trap1("trap1");
	ClapTrap	trap2;

	trap1.beRepaired(1);
	trap2.attack(trap2.getName());
	trap2.takeDamage(5);
	trap2.beRepaired(4);
	trap1.takeDamage(9);
	trap1.beRepaired(5000);
	trap2.beRepaired(5000);
	for (int i = 0; i < 10; i++)
		trap1.beRepaired(5000);
	trap2.takeDamage(5000);
	trap2.attack("Enemy 1");
	trap2.beRepaired(5000);
	trap2.takeDamage(1);
	return (0);
}