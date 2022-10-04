#include "HumanA.hpp"
#include <iostream>


void HumanA::attack (void)
{
	std::cout<<this->name<< " attacks with their "<<this->weapon->getType ()<<std::endl;
}

HumanA::HumanA(std::string name, Weapon *weapon)
{
	this->name = name;
	this->weapon =  weapon;
}

HumanA::HumanA()
{
	std::cout << "Constructing HumanA " << std::endl;
}

HumanA::~HumanA()
{
	std::cout<<"destroying HumanA "<<std::endl;
}