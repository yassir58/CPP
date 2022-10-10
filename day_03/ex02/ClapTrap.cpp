#include "ClapTrap.hpp"

ClapTrap::ClapTrap (void)
{
	std::cout << "ClapTrap Constructor" << std::endl;
	this->name = "Default ClapTrap";
	this->hitPoints = 10;
	this->attackDamage = 0;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap (std::string name)
{
	std::cout << "ClapTrap Parameter Constructor" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->attackDamage = 0;
	this->energyPoints = 10;
}

ClapTrap::~ClapTrap (void)
{
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &other)
{
	std::cout << "ClapTrap Copy Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints  = other.energyPoints;
	this->attackDamage = other.attackDamage;
}


ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap Copy assignement Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints  = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}


void ClapTrap::attack (const std::string &target)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage \
		<< " points of damage " << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energie" << std::endl;
}


void ClapTrap::beRepaired (unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " repair himself with " << amount <<  " points of energy" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy" << std::endl;
}


void ClapTrap::takeDamage (unsigned int amount)
{
	if (this->energyPoints - amount < 0)
		std::cout << "ClapTrap " << this->name << " has no energy" << std::endl;
	else
	{
		this->energyPoints -= amount; 
		std::cout << "ClapTrap " << this->name << " taken " << amount << " of damage" <<  std::endl;
	}
}