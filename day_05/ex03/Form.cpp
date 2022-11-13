#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form():__name ("Default form"), __formSigned(false), __signGrade(1), __executeGrade(1) 
{
	// std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string const &name, int const signGrade, int const executeGrade):__name (name), __formSigned(false), __signGrade(signGrade), __executeGrade(executeGrade) 
{
	// std::cout << "\e[0;32mParameter Constructor called of Form\e[0m" << std::endl;
	if (signGrade < Form::max || executeGrade < Form::max)
		throw Form::tooHigh;
	else if (signGrade > Form::min || executeGrade > Form::min)
		throw Form::tooLow;
}

Form::Form(const Form &copy):__name (copy.__name), __signGrade (copy.__signGrade), __executeGrade(copy.__executeGrade)
{
	// std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

// Destructor
Form::~Form()
{
	// std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form & Form::operator=(const Form &assign)
{
	this->__formSigned = assign.__formSigned;
	return *this;
}


bool Form::checkIfSigned (void) const 
{
	return (this->__formSigned);
}

std::string const &Form::getName (void) const
{
	return (this->__name);
}

int Form::getExecuteGrade (void) const
{
	return (this->__executeGrade);
}

int Form::getSignGrade (void) const 
{
	return (this->__signGrade);
}

std::ostream &operator<< (std::ostream &o, Form &fr)
{
	std::cout << "________________________________" <<std::endl;
	o << "Form name : " << fr.getName () << std::endl;
	o << "Form sign grade : " << fr.getSignGrade () << std::endl;
	o << "Form execute grade : " << fr.getExecuteGrade () << std::endl;
	if (fr.checkIfSigned() == true)
		o << "Form is signed "<< std::endl;
	else
		o << "Form is not signed " << std::endl;
	std::cout << "________________________________" <<std::endl;
	return (o);
}


void Form::beSigned (Bureaucrat const &br)
{
	if (br.getGrade () <= this->getSignGrade ())
		this->__formSigned = true ;
	else
		throw Form::tooLow;
}