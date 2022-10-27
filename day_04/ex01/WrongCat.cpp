#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat():type("WrongCat")
{
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
	this->brain =  new Brain ();
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
	delete this->brain;
}

// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	this->type = assign.type;
	return *this;
}

void WrongCat::makeSound (void) const 
{
	std::cout << "meyoooooooow" << std::endl;
}