#include "ScavTrap.hpp"

ScavTrap::ScavTrap (void)
{
	std::cout << "ScavTrap Constructor" << std::endl;
	this->name = "Default ScavTrap";
	this->hitPoints = 100;
	this->attackDamage = 20;
	this->energyPoints = 50;
}

ScavTrap::ScavTrap (std::string name)
{
	std::cout << "ScavTrap Parameter Constructor" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->attackDamage = 20;
	this->energyPoints = 50;
}

ScavTrap::~ScavTrap (void)
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const &other)
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScaveTrap Copy assignement Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return (*this);
}


void ScavTrap::gaurdGate (void)
{
	std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode. " << std::endl; 
}