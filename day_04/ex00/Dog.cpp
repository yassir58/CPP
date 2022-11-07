#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy):Animal ()
{
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
	this->type = copy.type;
}


// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->type = assign.type;
	return *this;
}

void Dog::makeSound (void) const 
{
	std::cout << "woof woof" << std::endl;
}

std::string Dog::getType (void) const
{
	return (this->type);
}