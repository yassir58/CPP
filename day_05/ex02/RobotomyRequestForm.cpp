#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm():__target("Default target")
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("Form", 72, 45), __target(target)
{
	std::cout << "\e[0;32mParameter Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):__target(copy.__target)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	(void) assign;
	return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int count_times = 0;
	
	if (this->checkIfSigned () == true)
	{
		if (executor.getGrade() < this->getExecuteGrade())
		{
			if (count_times % 2 == 0)
			{
				std::cout << "<< drilling noises >>" << std::endl;
				std::cout << this->__target <<  " has been robotomized successfully" << std::endl;
			}
			else
				std::cout << " the robotomy of " << this->__target << " failed" << std::endl;
		}
		else
			throw this->tooLow;
	}
	if (count_times < 100)
		count_times++;
	else if (count_times == 100)
		count_times = 0;
}