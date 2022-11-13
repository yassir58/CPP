#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"


class InvalidTarget: public std::exception 
{
	virtual const char* what() const throw();
};

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		Form *makeForm (std::string name, std::string target);
		Form *makeShrubbery (std::string target) const;
		Form *makePresdential (std::string target) const;
		Form *makeRobotomy (std::string target) const;
		InvalidTarget _InvalidTarget_;

		
	private:
		
};

#endif