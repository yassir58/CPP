#include "ScavTrap.hpp"

ScavTrap::ScavTrap (void)
{
	std::cout << "\e[0;33mScavTrap Constructor\e[0m" << std::endl;

}

ScavTrap::ScavTrap (std::string name)
{
	std::cout << "\e[0;32mScavTrap Parameter Constructor\e[0m" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	
}

ScavTrap::~ScavTrap (void)
{
	std::cout << "\e[0;31mScavTrap destructor\e[0m" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const &other)
{
	std::cout << "\e[0;32mScavTrap Copy Constructor\e[0m" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScaveTrap Copy assignement Constructor" << std::endl;
	this->name = other.name;
	return (*this);
}


void ScavTrap::gaurdGate (void)
{
	std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode. " << std::endl; 
}

void ScavTrap::attack (const std::string &target)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ScavTrap : " << this->name << " attacks " << target << " causing " << this->attackDamage \
		<< " points of damage " << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ScavTrap : " << this->name << " has no energie" << std::endl;
}