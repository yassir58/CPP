#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form():name ("Default form"), formSigned(false), signGrade(1), executeGrade(1) 
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string const &name, int const signGrade, int const executeGrade):name (name), formSigned(false), signGrade(1), executeGrade(1) 
{
	std::cout << "\e[0;33mParameter Constructor called of Form\e[0m" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::tooLow;
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::tooHigh;
}

Form::Form(const Form &copy):name (copy.name), signGrade (copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	(void) assign;
	return *this;
}


bool Form::checkIfSigned (void) const 
{
	return (this->formSigned);
}

std::string const &Form::getName (void) const
{
	return (this->name);
}

int const Form::getExecuteGrade (void) const
{
	return (this->executeGrade);
}

int const Form::getSignGrade (void) const 
{
	return (this->signGrade);
}

std::ostream &operator<< (std::ostream &o, Form &fr)
{
	o << "Form name : " << fr.getName () << std::endl;
	o << "Form sign grade : " << fr.getSignGrade () << std::endl;
	o << "Form execute grade : " << fr.getExecuteGrade () << std::endl;
	if (fr.checkIfSigned() == true)
		o << "Form is signed "<< std::endl;
	else
		o << "Form is not signed " << std::endl;
	return (o);
}


void Form::beSigned (Bureaucrat &br)
{
	if (br.getGrade () <= this->getSignGrade ())
		this->formSigned = true ;
	else
		throw Form::tooLow;
}