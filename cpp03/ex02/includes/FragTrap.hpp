#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

#define FRAG_HIT 100
#define FRAG_ENERGY 100
#define FRAG_ATTACK 30

class FragTrap: public ClapTrap {
    public:
        FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		virtual ~FragTrap(void);
		FragTrap &	operator=(FragTrap const & src);

		void highFivesGuys(void);
};

#endif