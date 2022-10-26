#include "Weapon.hpp"


std::string &Weapon::getType (void)
{
	std::string &ref = this->type;
	return (ref);
}

Weapon::Weapon()
{
	std::cout << "Constructing Weapon" << std::endl;
}

void Weapon::setType (std::string type)
{
	this->type = type;
}

Weapon::Weapon(std::string type)
{
	std::cout << "Constructing and initializing Weapon" << std::endl;
	this->type = type;
}

Weapon::Weapon (int *type)
{
	(void)type;
	this->type = "default weapon";
}

Weapon::~Weapon ()
{
	std::cout<<"destroying Weapon "<<std::endl;
}