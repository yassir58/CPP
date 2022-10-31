#include "FragTrap.hpp"

FragTrap::FragTrap (void)
{
	std::cout << "\e[0;33mFragTrap Constructor\e[0m" << std::endl;
	this->name = "Default FragTrap";
	this->hitPoints = 100;
	this->attackDamage = 30;
	this->energyPoints = 100;
}

FragTrap::FragTrap (std::string name)
{
	std::cout << "\e[0;32mFragTrap Parameter Constructor\e[0m" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->attackDamage = 30;
	this->energyPoints = 100;
}

FragTrap::~FragTrap (void)
{
	std::cout << "\e[0;31mFragTrap destructor\e[0m" << std::endl;
}

FragTrap::FragTrap (FragTrap const &other)
{
	std::cout << "\e[0;33mFragTrap Copy Constructor\e[0m" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "\e[0;33mFrageTrap Copy assignement Constructor\e[0m" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return (*this);
}

void FragTrap::attack (const std::string &target)
{
	if (this->energyPoints > 0)
	{
		std::cout << "FragTrap : " << this->name << " attacks " << target << " causing " << this->attackDamage \
		<< " points of damage " << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "FragpTrap : " << this->name << " has no energie" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants to high Five you " << std::endl; 
}