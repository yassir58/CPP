#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (void):ClapTrap("Default Clap")
{
	std::cout << "\e[0;33mDiamondTrap Constructor\e[0m" << std::endl;
	this->name = "Default DiamondTrap";
}

DiamondTrap::DiamondTrap (std::string name):ClapTrap (name + "_clap_name"), FragTrap (), ScavTrap()
{
	std::cout << "\e[0;32mDiamondTrap Parameter Constructor\e[0m" << std::endl;
	this->name = name;
	this->attackDamage = FragTrap::ad;
	this->energyPoints = ScavTrap::energyPoints;
	this->hitPoints = FragTrap::hp;
}


DiamondTrap::~DiamondTrap (void)
{
	std::cout << "\e[0;31mDiamondTrap destructor\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const &other)
{
	std::cout << "\e[0;32mDiamondTrap Copy Constructor\e[0;33m" << std::endl;
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

void DiamondTrap::whoAmI (void)const
{
	std::cout << "\e[0;33mDiamondTrap name : \e[0m" << this->name << std::endl;
	std::cout << "\e[0;33mClapTrap name    :\e[0m" <<  this->ClapTrap::name << std::endl;
}