#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
	this->type = "Wrong Cat";
	this->brain =  new Brain ();
}

WrongCat::WrongCat (WrongCat &copy)
{
	this->type = copy.type;
	this->brain = copy.brain;
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
	if (this->brain)
		delete brain;
	this->brain = assign.brain;
	return *this;
}

void WrongCat::makeSound (void) const 
{
	std::cout << "meyoooooooow" << std::endl;
}