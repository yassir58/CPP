#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors
Bureaucrat::Bureaucrat():__name ("Default Bereacrat"), __grade (1)
{
	// std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade):__name (name)
{
	// std::cout << "\e[0;32mParameterConstructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < Bureaucrat::max)
		throw Bureaucrat::tooHigh;
	else if (grade > Bureaucrat::min)
		throw Bureaucrat::tooLow;
	else 
		this->__grade = grade;
}

void Bureaucrat::incrementGrade (void)
{
	if (this->__grade  - 1 < Bureaucrat::max)
		throw Bureaucrat::tooHigh;
	else
	{
		this->__grade--;
	}
}

void Bureaucrat::decrementGrade (void)
{
	if (this->__grade   + 1 > Bureaucrat::min)
		throw Bureaucrat::tooLow;
	else
	{
		this->__grade++;
	}
}


int Bureaucrat::getGrade (void) const
{
	return (this->__grade);
}

void Bureaucrat::setGrade (int grade)
{
	if (grade < Bureaucrat::max)
		throw Bureaucrat::tooHigh;
	else if (grade > Bureaucrat::min)
		throw Bureaucrat::tooLow;
	else 
		this->__grade = grade;
}

std::string Bureaucrat::getName (void) const
{
	return (this->__name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):__name (copy.__name)
{
	// std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	this->__grade = copy.__grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	// std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->__grade = assign.__grade;
	return *this;
}

const char * GradeTooHighException::what (void) const throw ()
{
	return (" \e[0;31m<< Grade too high >>\e[0m ");
}

const char * GradeTooLowException::what (void) const throw ()
{
	return (" \e[0;31m<< Grade too low >> \e[0m ");
}


std::ostream& operator << (std::ostream &o, Bureaucrat const &obj)
{
	o << obj.getName() << ", Bureaucrat Grade " << obj.getGrade() << std::endl;
	return (o);
}


void Bureaucrat::signForm (std::string name, bool sign)
{
	if (sign)
		std::cout << this->getName () << " signed " << name << std::endl;
	else 
		std::cout << this->getName () << " couldn't sign " << name << " because grade was to low" << std::endl;
}



void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}