#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat():name ("Default Bereuacrat"), grade (1)
{
	// std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grd):name (name)
{
	// std::cout << "\e[0;32mParameter Constructor called of Bureaucrat\e[0m" << std::endl;
	if (grd < Bureaucrat::max)
		throw Bureaucrat::tooHigh;
	else if (grd > Bureaucrat::min)
		throw Bureaucrat::tooLow;
	else
		this->grade = grd ;
}

void Bureaucrat::incrementGrade (void)
{
	if (this->grade  - 1 < Bureaucrat::max)
		throw Bureaucrat::tooHigh;
	else
	{
		this->grade--;
	}
}

void Bureaucrat::decrementGrade (void)
{
	if (this->grade   + 1 > Bureaucrat::min)
		throw Bureaucrat::tooLow;
	else
	{
		this->grade++;
	}
}


int Bureaucrat::getGrade (void) const
{
	return (this->grade);
}

void Bureaucrat::setGrade (int grd)
{
	if (grd < Bureaucrat::max)
		throw Bureaucrat::tooHigh;
	else if (grd > Bureaucrat::min)
		throw Bureaucrat::tooLow;
	else
		this->grade = grd ;
}

std::string Bureaucrat::getName (void) const
{
	return (this->name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):name (copy.name)
{
	// std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	this->grade = copy.grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	// std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->grade = assign.grade;
	return *this;
}

const char * GradeTooHighException::what (void) const throw ()
{
	return ("\e[0;31m<< Grade too high >>\e[0m");
}

const char * GradeTooLowException::what (void) const throw ()
{
	return ("\e[0;31m << Grade too low >> \e[0m");
}


std::ostream& operator << (std::ostream &o, Bureaucrat const &obj)
{
	o << obj.getName() << ", Bureaucrat Grade " << obj.getGrade();
	return (o);
}