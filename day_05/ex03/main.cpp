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


	try
	{
		Form *test = NULL;

		test = a.makeForm ("undefined", "test");
		test->beSigned (br);
	}
	catch (std::exception &exc)
	{
		std::cout << exc.what () << std::endl;
	}

	{
		Form *fr = NULL;


		try 
		{
			fr = b.makeForm ("shrubbery creation", "shrubbery");
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what () << std::endl;
		}

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
		Form *fr = NULL;
		try
		{
			fr = b.makeForm ("robotomy request", "robotomy");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
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

	/// will throw an exception
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

	/// will not throw an exception
	{
		Bureaucrat br("bureaucrat", 5);
		Form *fr = NULL;

		try 
		{
 			fr = b.makeForm ("presdential pardon", "presdential");
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what () << std::endl;
		}

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