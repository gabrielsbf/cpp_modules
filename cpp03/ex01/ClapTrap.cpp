
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Default ClapTrap"),
	_hitPoints(ClapTrap::initHitPoints),
	_energyPoints(ClapTrap::initEnergyPoints),
	_attackDamage(ClapTrap::initAttackDamage) {
	std::cout << "Default Claptrap was constructed." << std::endl;
	
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(ClapTrap::initHitPoints),
	_energyPoints(ClapTrap::initEnergyPoints),
	_attackDamage(ClapTrap::initAttackDamage) {
	std::cout << "A ClapTrap named \"" << name << "\" was constructed." << std::endl;
	
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy constructor was called." << std::endl;
	*this = src;
	
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor was called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {
	std::cout << "ClapTrap assignment constructor was called." << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void	ClapTrap::attack(std::string & target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't attack: destroyed." << std::endl;
		
	}
	if (this->_energyPoints == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't attack: out of energy points."
			<< std::endl;
		
	}
	if (target == this->_name)
		target = "itself";
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name
		<< " attacks " << target << " and hits for " << this->_attackDamage
		<< " damage!"  << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't take anymore damage: has been destroyed" << std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0) {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name
			<< " takes " << amount << " damage and is destroyed!" << std::endl;
	}
	else {
		this->_hitPoints -= amount;
		std::cout <<  "ClapTrap " << this->_name
			<< " takes " << amount << " damage!" << std::endl;
	}
	
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't repair itself: already destroyed" << std::endl;
			return ;
	}
	else if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't repair itself: out of energy points" << std::endl;
			return ;	
	}
	else if ((this->_hitPoints + amount) > this->initHitPoints)
		amount = this->initHitPoints - this->_hitPoints;
		
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout <<  "ClapTrap " << this->_name << " repairs itself for " << amount << "."  << std::endl;
}