#include "fragTrap.hpp"

fragTrap::fragTrap (void)
{
	std::cout << "fragTrap Constructor" << std::endl;
	this->name = "Default fragTrap";
	this->hitPoints = 100;
	this->attackDamage = 30;
	this->energyPoints = 100;
}

fragTrap::fragTrap (std::string name)
{
	std::cout << "fragTrap Parameter Constructor" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->attackDamage = 30;
	this->energyPoints = 100;
}

fragTrap::~fragTrap (void)
{
	std::cout << "fragTrap destructor" << std::endl;
}

fragTrap::fragTrap (fragTrap const &other)
{
	std::cout << "fragTrap Copy Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
}

fragTrap &fragTrap::operator=(fragTrap const &other)
{
	std::cout << "frageTrap Copy assignement Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return (*this);
}


void fragTrap::highFivesGuys(void)
{
	std::cout << "fragTrap " << this->name << " wants to high Five you " << std::endl; 
}