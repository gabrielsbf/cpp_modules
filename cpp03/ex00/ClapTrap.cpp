
#include "ClapTrap.hpp"

//Constructors & Destructor
ClapTrap::ClapTrap(void)
	: _name("Default ClapTrap"),
	_hitPoints(CLAP_HIT),
	_maxHitPoints(CLAP_HIT),
	_energyPoints(CLAP_ENERGY),
	_maxEnergyPoints(CLAP_ENERGY),
	_attackDamage(CLAP_ATTACK),
	_maxAttackDamage(CLAP_ATTACK) {
	std::cout << "Default Claptrap was constructed." << std::endl;
	
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(CLAP_HIT),
	_maxHitPoints(CLAP_HIT),
	_energyPoints(CLAP_ENERGY),
	_maxEnergyPoints(CLAP_ENERGY),
	_attackDamage(CLAP_ATTACK),
	_maxAttackDamage(CLAP_ATTACK) {
	std::cout << "A ClapTrap named \"" << name << "\" was constructed." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy constructor was called." << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Instance of ClapTrap " << this->getName() << " is being destroyed" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {
	std::cout << "ClapTrap assignment constructor was called." << std::endl;
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

//Getters
const std::string  &ClapTrap::getName(void) const
{
	return (_name);
}


unsigned int	ClapTrap::getMaxHitPoints(void) const 
{
	return (this->_maxHitPoints);
}

unsigned int	ClapTrap::getMaxAttackDamage(void) const
{
	return (this->_maxAttackDamage);
}
		
unsigned int	ClapTrap::getMaxEnergyPoints(void) const
{
	return (this->_maxEnergyPoints);
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

void	ClapTrap::setName(std::string newName)
{
	this->_name = newName;
}
//Functions
void	ClapTrap::attack(const std::string & target) 
{	
	std::cout << "********* ATACKING *********" << std::endl;
	std::string nameTarget = target;
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't attack: destroyed." << std::endl;
		std::cout << "*****************************" << std::endl;
			return ;
		
	}
	if (this->_energyPoints == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't attack: out of energy points."
			<< std::endl;
		std::cout << "*****************************" << std::endl;
			return ;
		
	}
	if (target == this->_name)
		nameTarget = "itself";
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name
		<< " attacks " << nameTarget << " and hits for " << this->_attackDamage
		<< " damage!"  << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) 
{
	std::cout << "********* TAKING DMG *********" << std::endl;
	if (this->_hitPoints == 0) 
	{
		std::cout <<  "ClapTrap " << this->_name
			<< " can't take anymore damage: has been destroyed" << std::endl;
		std::cout << "*****************************" << std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0) 
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name
			<< " takes " << amount << " damage and is destroyed!" << std::endl;
	}
	else 
	{
		this->_hitPoints -= amount;
		std::cout <<  "ClapTrap " << this->_name
			<< " takes " << amount << " damage!" << std::endl;
	}
	std::cout << "*****************************" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "********* REPAIRING *********" << std::endl;
	std::cout << this->getName() << " Energy points are: "<< this->_energyPoints << std::endl;
	if (this->_hitPoints == 0) 
	{
		std::cout << "ClapTrap " << this->_name
			<< " can't repair itself: already destroyed" << std::endl;
		std::cout << "*****************************" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0) 
	{
		std::cout << "ClapTrap " << this->_name
			<< " can't repair itself: out of energy points" << std::endl;
		std::cout << "*****************************" << std::endl;
		return ;	
	}
	else if ((this->_hitPoints + amount) > this->_maxHitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;
		
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout <<  "ClapTrap " << this->_name << " repairs itself for " << amount << "."  << std::endl;
	std::cout << "*****************************" << std::endl;
}