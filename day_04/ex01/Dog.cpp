#include "Dog.hpp"
#include "Brain.hpp"

// Constructors
Dog::Dog()
{
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
	this->brain = new Brain ();
	this->type = "Dog";
}

Dog::Dog(const Dog &copy):Animal ()
{
	std::cout << "\e[0;32mCopy Constructor called of Dog\e[0m" << std::endl;
	this->type = copy.type;
	this->brain = new Brain ();
	*this->brain = *copy.brain ;
}


// Destructor
Dog::~Dog()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->type = assign.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain ();
	*this->brain = *assign.brain ;
	return *this;
}

void Dog::makeSound (void) const 
{
	std::cout << "woof woof" << std::endl;
}

std::string Dog::getType (void) const
{
	return (this->type);
}


Brain *Dog::getBrain (void) const
{
	return (this->brain);
}