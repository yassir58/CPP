#include "HumanB.hpp"

void HumanB::attack (void)
{
	if (this->weapon == NULL)
		std::cout << "HumanB doesn't have a weapon but he's still dangerous " << std::endl;
	else
		std::cout<<this->name<< " attacks with their "<<this->weapon->getType ()<<std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
	std::cout << "Constructing and initializing HumanB " << std::endl;
	this->weapon = NULL;
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