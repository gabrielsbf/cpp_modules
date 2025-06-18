
#include "includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap Default Constructor - Name ScavTrap Default" << std::endl;
	this->_name = "ScavTrap Default";
	this->_hitPoints = SCAV_HIT;
	this->_attackDamage = SCAV_ATTACK;
	this->_energyPoints = SCAV_ENERGY;
	this->_maxEnergyPoints = SCAV_ENERGY;
	this->_maxAttackDamage = SCAV_ATTACK;
	this->_maxHitPoints = SCAV_HIT;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Default Constructor - Name \""<< name << "\"" << std::endl;;
	this->_hitPoints = SCAV_HIT;
	this->_attackDamage = SCAV_ATTACK;
	this->_energyPoints = SCAV_ENERGY;
	this->_maxEnergyPoints = SCAV_ENERGY;
	this->_maxAttackDamage = SCAV_ATTACK;
	this->_maxHitPoints = SCAV_HIT;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap() {
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Instance of ScavTrap " << this->getName() << " is being destroyed" << std::endl;
	return ;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & src) {
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

void	ScavTrap::attack(const std::string & target)
{
	std::cout << "********* ATACKING *********" << std::endl;
	std::string nameTarget = target;
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name
			<< " can't attack: destroyed." << std::endl;
		std::cout << "*****************************" << std::endl;
		return ;		
	}
	if (this->_energyPoints == 0) {
		std::cout <<  "ScavTrap " << this->_name
			<< " can't attack: out of energy points."
			<< std::endl;
		std::cout << "*****************************" << std::endl;
		return ;
	}
	if (target == this->_name)
		nameTarget = "itself";
	_energyPoints--;
	std::cout <<  "ScavTrap " << this->_name
		<< " leaps on " << nameTarget << " and crushes it for " << this->_attackDamage
		<< " damage!"  << std::endl;  
}

void	ScavTrap::guardGate(void) {
	if (this->_hitPoints == 0)
		std::cout << this->_name
			<< "can't guard the gate in its broken state."  << std::endl;
	else
		std::cout << this->_name
			<< " switches to Gate guarding mode."  << std::endl;
	return ;
}