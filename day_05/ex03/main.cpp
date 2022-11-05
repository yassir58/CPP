#include "Bureaucrat.hpp"
// #include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int main ()
{
	Intern a;
	Intern b;
	Bureaucrat br("bureaucrat", 5);
	Bureaucrat wr("wrong", 123);


	{
		Form *fr = NULL;

		a.makeForm("Undefined form", "test");
		fr = b.makeForm ("shrubbery creation", "shrubbery");
		try 
		{
			fr->beSigned (br);
		}
		catch (std::exception &exc)
		{
			std::cout << "failed to sign form : " << exc.what () << std::endl;
		}
		br.executeForm (*fr);
		delete fr;
	}	

	{
		Form *fr = b.makeForm ("robotomy request", "robotomy");
		try 
		{
			fr->beSigned (br);
		}
		catch (std::exception &exc)
		{
			std::cout << "failed to sign form : " << exc.what () << std::endl;
		}
		br.executeForm (*fr);	
		delete fr;	
	}

	{
		Bureaucrat br("bureaucrat", 6);
		Form *fr = b.makeForm ("presdential pardon", "presdential");
		try 
		{
			fr->beSigned (br);
		}
		catch (std::exception &exc)
		{
			std::cout << "failed to sign form : " << exc.what () << std::endl;
		}
		br.executeForm (*fr);	
		delete fr;	
	}
}