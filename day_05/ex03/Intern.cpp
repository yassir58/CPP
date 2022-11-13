#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// Constructors
Intern::Intern()
{
	// std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	// std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	// std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

const char * InvalidTarget::what (void) const throw ()
{
	return ("\e[0;31m ----- Invalid target ----- \e[0m");
}

Form *Intern::makeShrubbery (std::string target) const
{
	Form *form = NULL;

	form =  new ShrubberyCreationForm (target);
	return (form);
}
Form *Intern::makePresdential (std::string target) const
{
	Form *form = NULL;

	form = new PresidentialPardonForm (target);
	return (form);

}
Form *Intern::makeRobotomy (std::string target) const
{
	Form *form = NULL;

	form = new RobotomyRequestForm (target);
	return (form);
}


Form *Intern::makeForm (std::string name, std::string target)
{
	int indx = 0;
	
	std::string requests[3] = {"shrubbery creation", "presdential pardon" ,"robotomy request" };
	Form *(Intern:: *funcPtr[3])(std::string target) const;

	funcPtr[0] = &Intern::makeShrubbery ;
	funcPtr[1] = &Intern::makePresdential ;
	funcPtr[2] = &Intern::makeRobotomy ;

	for (indx = 0; indx < 3 ; indx++)
	{
		if (!name.compare(requests[indx]))
			break;
	}
	if (indx != 3)
		return ((this->*funcPtr[indx])(target));
	else 
		throw Intern::_InvalidTarget_;
	return (NULL);
}