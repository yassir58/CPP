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

// Cat::Cat(std::string idea)
// {
// 	std::cout << "\e[0;32mParameter Constructor called of Cat\e[0m" << std::endl;
// 	this->brain =  new Brain (idea);
// }

// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
	delete this->brain;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.type;
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

// void Cat::printIdeas (void)  const 
// {
// 	for (int i = 0;i < this->brain->count ; i++)
// 		std::cout << this->brain->getIdea(i) << " ";
// }