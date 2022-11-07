#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy):Animal ()
{
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
	this->type = copy.type ;
}


// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.type;
	return *this;
}

void Cat::makeSound (void) const 
{
	std::cout << "meyoooooooow" << std::endl;
}

std::string Cat::getType (void) const
{
	return (this->type);
}