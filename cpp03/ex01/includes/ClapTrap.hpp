#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>


class ClapTrap
{
	public:
		static unsigned int const	initHitPoints = 10;
		static unsigned int const	initEnergyPoints = 10;
		static unsigned int const	initAttackDamage = 0;

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
        ClapTrap(void);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);
		
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		
		void		attack(std::string & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

# endif