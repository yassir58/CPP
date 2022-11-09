#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
	this->type = copy.type;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return *this;
}

void WrongAnimal::makeSound (void) const
{
	std::cout << "Generic animal sound " << std::endl;
}


std::string WrongAnimal::getType (void) const
{
	return (this->type);
}