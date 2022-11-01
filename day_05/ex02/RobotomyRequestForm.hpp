#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string const __target;
		// int const __signGrade;
		// int const __executeGrade;
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		// Destructor
		~RobotomyRequestForm();
		
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);

		void execute(Bureaucrat const & executor) const;
			
};

#endif