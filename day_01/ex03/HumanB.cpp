#include "HumanB.hpp"

void HumanB::attack (void)
{
	std::cout<<this->name<< " attacks with their "<<this->weapon.getType ()<<std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::HumanB()
{
	std::cout << "Constructing HumanB " << std::endl;
}

HumanB::~HumanB()
{
	std::cout<<"destroying HumanB "<<std::endl;
}