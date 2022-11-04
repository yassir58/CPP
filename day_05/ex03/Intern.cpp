#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}


Form *Intern::makeForm (std::string name, std::string target)
{
	int indx = 0;
	Form *form = NULL;
	std::string requests[3] = {"shrubbery creation", "presdential pardon" ,"robotomy request" };

	for (indx = 0; indx < 3 ; indx++)
	{
		if (!name.compare(requests[indx]))
			break;
	}
	switch (indx)
	{
		case 0:
			form =  new ShrubberyCreationForm (target);
		break;
		case 1:
			form = new PresidentialPardonForm (target);
		break;
		case 2:
			form = new RobotomyRequestForm (target);
		break;
		default:
			std::cerr << "No form name matches !" << std::endl;
	}
	return (form);
}