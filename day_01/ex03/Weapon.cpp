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
	this->type = type;
}

Weapon::~Weapon ()
{
	std::cout<<"destroying Weapon "<<std::endl;
}