#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include "ClapTrap.hpp"

#define SCAV_HIT 100
#define SCAV_ENERGY 50
#define SCAV_ATTACK 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string & name);
		ScavTrap(ScavTrap const & src);
		virtual ~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const & src);

		virtual void	attack(std::string & target);
		void	guardGate(void);
};

#endif