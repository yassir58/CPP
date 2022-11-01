#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm():__target ("Default Target")
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form ("Form", 25, 5), __target(target)
{
	std::cout << "\e[0;32mParameter Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):__target(copy.__target) 
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	(void) assign;
	return *this;
}

void PresidentialPardonForm::execute (Bureaucrat const &executor) const
{
	if (this->checkIfSigned () == true)
	{
		if (executor.getGrade() < this->getExecuteGrade())
		{
			std::cout << this->__target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
		else
			throw this->tooLow;	
	}
}