#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (void)
{
	std::cout << "DiamondTrap Constructor" << std::endl;
	this->name = "Default DiamondTrap";
	this->hitPoints = 100;
	this->attackDamage = 20;
	this->energyPoints = 50;
}

DiamondTrap::DiamondTrap (std::string name)
{
	std::cout << "DiamondTrap Parameter Constructor" << std::endl;
	this->name = name + "_clap_name";
	this->hitPoints = 100;
	this->attackDamage = 20;
	this->energyPoints = 50;
}

DiamondTrap::~DiamondTrap (void)
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const &other)
{
	std::cout << "DiamondTrap Copy Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondeTrap Copy assignement Constructor" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return (*this);
}
