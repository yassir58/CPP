#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm():__target("Default target")
{
	// std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): Form("Form", 145, 137), __target(target)
{
	// std::cout << "\e[0;32mParameter Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):__target(copy.__target)
{
	// std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	(void) assign;
	return *this;
}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
	std::fstream out_file;

	if (this->checkIfSigned () == true)
	{
		if (executor.getGrade() <= this->getExecuteGrade())
		{
			out_file.open(this->__target + "_shrubbery", std::ios::out);
			if (!out_file)
			{
				std::cout << "failed to open file for writing!"<<std::endl;
				exit (EXIT_FAILURE);
			}
			out_file << "       #########	" << std::endl;
			out_file << "     ###|### |/####	" << std::endl;
			out_file << "   ##//##/_/##/_#//|##" << std::endl;
			out_file << "  ##|/#/-##|/ ||## #####" << std::endl;
			out_file << "  ####/-### | #/###_/_####" << std::endl;
			out_file << " ##/|##//-### #|/#### ##/##" << std::endl;
			out_file << "###~#~###_###|{,#######-~###" << std::endl;
			out_file << "             }{" << std::endl;
			out_file << "             }{" << std::endl;
			out_file << "             }{" << std::endl;
			out_file.close ();
		}
		else
			throw this->tooLow;
	}
	else
		std::cout << "Form is not signed " << std::endl;	
}
