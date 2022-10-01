#include "Zombie.hpp"


Zombie::~Zombie()
{
	std::cout<<"destroying :"<<this->name<<std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	std::cout<<"Dummy constructor"<<std::endl;
}

void Zombie::announce(void)
{
	std::cout<<this->name<<" : BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}