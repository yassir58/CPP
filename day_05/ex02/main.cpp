#include "Bureaucrat.hpp"
// #include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main ()
{
	Bureaucrat a("a", 5);
	Bureaucrat d ("d", 1);
	Bureaucrat b("b", 148);


	ShrubberyCreationForm  sh("shrubbery");
	RobotomyRequestForm    rb("robotomy");
	PresidentialPardonForm prd ("presdential");




	try 
	{
		sh.beSigned (a);
		rb.beSigned (a);
		prd.beSigned (d);
	}
	catch (std::exception &exc)
	{
		std::cout << "failed to sign form" << std::endl;
		std::cout << exc.what() << std::endl;
	}


	// will create shrubbery tree
	try
	{
		sh.execute (a);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what() << std::endl;
	}

	// will throw an exception
	try 
	{
		sh.execute (b);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}

	// will throw an exception
	b.executeForm (sh);
	
	/// robotomy request 
	try 
	{
		rb.execute (a);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}
	
	// robotomy request failed
	try 
	{
		rb.execute (a);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}

	// presedential pardon
	try 
	{
		prd.execute (d);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}

	// will throw an exception
	try 
	{
		Bureaucrat a("a", 8);
		prd.execute (a);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}
}