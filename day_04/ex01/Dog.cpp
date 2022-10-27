#include "Dog.hpp"
#include "Brain.hpp"

// Constructors
Dog::Dog():type ("Dog")
{
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
	this->brain = new Brain ();
}

Dog::Dog(const Dog &copy):Animal ()
{
	std::cout << "\e[0;32mCopy Constructor called of Dog\e[0m" << std::endl;
	this->type = copy.type;
	this->brain = new Brain ();
}


// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
	delete this->brain;
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