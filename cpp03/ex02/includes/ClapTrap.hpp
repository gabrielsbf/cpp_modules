#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

#define CLAP_HIT 10
#define CLAP_ENERGY 10
#define CLAP_ATTACK 0

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
        ClapTrap(void);
		virtual ~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);
		
		const std::string	&getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergyPoints(void) const;
		unsigned int		getAttackDamage(void) const;
		unsigned int		getMaxHitPoints(void) const;
		unsigned int		getMaxEnergyPoints(void) const;
		unsigned int		getMaxAttackDamage(void) const;
		void				setName(std::string newName);
		virtual void		attack(const std::string & target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_maxHitPoints;
		unsigned int	_energyPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_attackDamage;
		unsigned int	_maxAttackDamage;
};

# endif