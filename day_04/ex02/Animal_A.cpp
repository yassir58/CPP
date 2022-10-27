#include "Animal_A.hpp"

// Constructors
Animal_A::Animal_A()
{
	this->type = "ordinary animal_A";
	std::cout << "\e[0;33mDefault Constructor called of Animal_A\e[0m" << std::endl;
}

Animal_A::Animal_A(const Animal_A &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Animal_A\e[0m" << std::endl;
}


// Destructor
Animal_A::~Animal_A()
{
	std::cout << "\e[0;31mDestructor called of Animal_A\e[0m" << std::endl;
}


// Operators
Animal_A & Animal_A::operator=(const Animal_A &assign)
{
	(void) assign;
	return *this;
}

std::string Animal_A::getType (void) const
{
	return (this->type);
}