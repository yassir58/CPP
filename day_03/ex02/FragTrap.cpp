#include "FragTrap.hpp"

FragTrap::FragTrap (void)
{
	std::cout << "FragTrap Constructor" << std::endl;
	this->name = "Default FragTrap";
	this->hitPoints = 100;
	this->attackDamage = 30;
	this->energyPoints = 100;
}

FragTrap::FragTrap (std::string name)
{
	std::cout << "FragTrap Parameter Constructor" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->attackDamage = 30;
	this->energyPoints = 100;
}

FragTrap::~FragTrap (void)
{
	std::cout << "FragTrap destructor" << std::endl;
}

FragTrap::FragTrap (FragTrap const &other)
{
	std::cout << "FragTrap Copy Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "frageTrap Copy assignement Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return (*this);
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants to high Five you " << std::endl; 
}