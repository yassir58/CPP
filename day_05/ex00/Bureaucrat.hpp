#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>


class GradeTooHighException: public std::exception 
{
	virtual const char* what(void) const throw();
};
class GradeTooLowException: public std::exception 
{
	virtual const char* what(void) const throw();
};

class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat (std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat & operator=(const Bureaucrat &assign);

		std::string getName (void) const;
		int getGrade (void) const;
		void setGrade (int grd);
		void incrementGrade (void);
		void decrementGrade (void);


		GradeTooHighException tooHigh;
		GradeTooLowException tooLow;
		static int const min = 150;
		static int const max = 1;
	
};

std::ostream& operator << (std::ostream &o, Bureaucrat const &obj);

#endif