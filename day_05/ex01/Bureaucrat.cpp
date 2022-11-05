#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors
Bureaucrat::Bureaucrat():__name ("Default Bereacrat"), __grade (1)
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade):__name (name), __grade (grade)
{
	std::cout << "\e[0;32mParameterConstructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::tooLow;
	else if (grade > 150)
		throw Bureaucrat::tooHigh;
}

void Bureaucrat::incrementGrade (void)
{
	if (this->__grade  - 1 < 1)
		throw Bureaucrat::tooLow;
	else
	{
		this->__grade--;
	}
}

void Bureaucrat::decrementGrade (void)
{
	if (this->__grade   + 1 > 150)
		throw Bureaucrat::tooHigh;
	else
	{
		this->__grade++;
	}
}


int Bureaucrat::getGrade (void) const
{
	return (this->__grade);
}

std::string Bureaucrat::getName (void) const
{
	return (this->__name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):__name (copy.__name)
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	this->__grade = copy.__grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->__grade = assign.__grade;
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
	o << obj.getName() << ", Bureaucrat Grade " << obj.getGrade() << std::endl;
	return (o);
}


void Bureaucrat::signForm (Form &form)
{
	try 
	{
		form.beSigned(*this);
	}
	catch (std::exception &exc)
	{
		std::cout << this->getName () << " Couldn't sign " << form.getName () << " because " << exc.what() << std::endl;
		return; 
	}
	std::cout << this->getName () << " signed " << form.getName () << std::endl;
}

