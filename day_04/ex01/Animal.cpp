#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
	this->type = copy.type;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	this->type = assign.type;
	return *this;
}

void Animal::makeSound (void) const
{
	std::cout << "Generic animal sound " << std::endl;
}


std::string Animal::getType (void) const
{
	return (this->type);
}