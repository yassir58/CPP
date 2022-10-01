#include "Zombie.hpp"


Zombie::~Zombie()
{
	std::cout<<this->name<<std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout<<this->name<<" : BraiiiiiiinnnzzzZ..."<<std::endl;
}

