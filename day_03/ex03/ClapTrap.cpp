#include "ClapTrap.hpp"

ClapTrap::ClapTrap (void):name("Default ClapTrap"), hitPoints(10), energyPoints (10), attackDamage(0)  
{
	std::cout << "\e[0;33mClapTrap Constructor\e[0m" << std::endl;
}

ClapTrap::ClapTrap (std::string name):name(name), hitPoints(10), energyPoints (10), attackDamage(0) 
{
	std::cout << "\e[0;32mClapTrap Parameter Constructor\e[0m" << std::endl;
}

ClapTrap::~ClapTrap (void)
{
	std::cout << "\e[0;31mClapTrap destructor\e[0m" << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &other)
{
	std::cout << "\e[0;32mClapTrap Copy Constructor\e[0m" << std::endl;
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
		std::cout << "ClapTrap : " << this->name << " attacks " << target << " causing " << this->attackDamage \
		<< " points of damage " << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap : " << this->name << " has no energie" << std::endl;
}


void ClapTrap::beRepaired (unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ClapTrap : " << this->name << " repair himself with " << amount <<  " points of energy" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
		std::cout << "ClapTrap : " << this->name << " has no energy" << std::endl;
}


void ClapTrap::takeDamage (unsigned int amount)
{
	if (this->energyPoints - amount < 0)
		std::cout << "ClapTrap : " << this->name << " has no energy" << std::endl;
	else
	{
		this->energyPoints -= amount; 
		std::cout << "ClapTrap : " << this->name << " taken " << amount << " of damage" <<  std::endl;
	}
}