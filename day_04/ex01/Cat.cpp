#include "Cat.hpp"
#include "Brain.hpp"

// Constructors
Cat::Cat()
{
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
	this->type = "Cat";
	this->brain =  new Brain ();
}

Cat::Cat(const Cat &copy):Animal ()
{
	std::cout << "\e[0;32mCopy Constructor called of Cat\e[0m" << std::endl;
	this->type = copy.type;
	this->brain = new Brain ();
	*this->brain = *copy.brain ;
}


// Destructor
Cat::~Cat()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain ();
	*this->brain = *assign.brain ;
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

Brain *Cat::getBrain (void) const
{
	return (this->brain);
}