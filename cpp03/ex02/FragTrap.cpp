
#include "includes/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap Default Constructor - Name FragTrap Default" << std::endl;
	this->_name = "FragTrap Default";
	this->_hitPoints = FRAG_HIT;
	this->_attackDamage = FRAG_ATTACK;
	this->_energyPoints = FRAG_ENERGY;
	this->_maxEnergyPoints = FRAG_ENERGY;
	this->_maxAttackDamage = FRAG_ATTACK;
	this->_maxHitPoints = FRAG_HIT;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Default Constructor - Name \""<< name << "\"" << std::endl;;
	this->_hitPoints = FRAG_HIT;
	this->_attackDamage = FRAG_ATTACK;
	this->_energyPoints = FRAG_ENERGY;
	this->_maxEnergyPoints = FRAG_ENERGY;
	this->_maxAttackDamage = FRAG_ATTACK;
	this->_maxHitPoints = FRAG_HIT;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap() {
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "Instance of FragTrap " << this->getName() << " is being destroyed" << std::endl;
	return ;
}

FragTrap &	FragTrap::operator=(FragTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
		this->_maxEnergyPoints = src.getMaxEnergyPoints();
		this->_maxHitPoints = src.getMaxHitPoints();
		this->_maxAttackDamage = src.getMaxAttackDamage();
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() 
		<< " Couldn't hi five because it's destroyed" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() 
		<< " Couldn't hi five because it's out of energy"<< std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "FragTrap " << this->getName() 
	<< " stands it's hands for the most epic hi five" << std::endl;
	return ;
}
