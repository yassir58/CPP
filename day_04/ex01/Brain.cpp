#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "\e[0;33mBrain Constructor \e[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "random idea" ;
}



Brain::Brain( const Brain & src )
{
	std::cout << "\e[0;33mBrain Copy Constructor\e[0m" << std::endl;
	for (int i = 0; i < Brain::count; i++)
		this->ideas[i] = src.getIdea (i);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "\e[0;31mBrain Destructor\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << "\e[0;32mBrain copy Assignement  \e[0m" << std::endl;
	for (int i = 0; i < Brain::count; i++)
		this->ideas[i] = rhs.getIdea (i);
	return *this;
}


std::string Brain::getIdea (int indx) const
{
	return (this->ideas[indx]);
}

void Brain::setIdea (std::string idea, int indx)
{
	if (indx <= 99)
		this->ideas[indx] = idea;
}