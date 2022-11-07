#include "Animal_A.hpp"

// Constructors
Animal_A::Animal_A()
{
	std::cout << "\e[0;33mDefault Constructor called of Animal_A\e[0m" << std::endl;
	this->type = "animal_A";
}

Animal_A::Animal_A(const Animal_A &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Animal_A\e[0m" << std::endl;
	this->type = copy.type;
}


// Destructor
Animal_A::~Animal_A()
{
	std::cout << "\e[0;31mDestructor called of Animal_A\e[0m" << std::endl;
}


// Operators
Animal_A & Animal_A::operator=(const Animal_A &assign)
{
	this->type = assign.type;
	return *this;
}

std::string Animal_A::getType (void) const
{
	return (this->type);
}