#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
	private:
		std::string const name;
		bool formSigned;
		int const signGrade;
		int const executeGrade;
	public:
		// Constructors
		Form();
		Form(std::string const &name, int const signGrade, int const executeGrade);
		Form(const Form &copy);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);

		std::string const &getName (void) const ;
		bool checkIfSigned (void) const;
		int getSignGrade (void) const;
		int getExecuteGrade (void) const ;

		void beSigned (Bureaucrat &br);
		
	private:
		
};


std::ostream &operator<< (std::ostream &o, Form &fr);

#endif