#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat():name ("Default Bereacrat"), grade (1)
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade):name (name)
{
	std::cout << "\e[0;32mParameterConstructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::tooLow;
	else if (grade > 150)
		throw Bureaucrat::tooHigh;
	else
		this->grade = grade ;
}

void Bureaucrat::incrementGrade (void)
{
	if (this->grade  - 1 < 1)
		throw Bureaucrat::tooLow;
	else
	{
		this->grade--;
	}
}

void Bureaucrat::decrementGrade (void)
{
	if (this->grade   + 1 > 150)
		throw Bureaucrat::tooHigh;
	else
	{
		this->grade++;
	}
}


int Bureaucrat::getGrade (void) const
{
	return (this->grade);
}

std::string Bureaucrat::getName (void) const
{
	return (this->name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):name (copy.name)
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	this->grade = copy.grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->grade = assign.grade;
	return *this;
}

const char * GradeTooHighException::what (void) const throw ()
{
	return ("Grade too high");
}

const char * GradeTooLowException::what (void) const throw ()
{
	return ("Grade too low");
}


std::ostream& operator << (std::ostream &o, Bureaucrat const &obj)
{
	o << obj.getName() << ", Bureaucrat Grade " << obj.getGrade() << std::endl;
	return (o);
}