#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &copy):WrongAnimal ()
{
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
	this->type = copy.type ;
}


// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
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