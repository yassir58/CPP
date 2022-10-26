#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	this->type = "ordinary animal";
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	(void) assign;
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