#include "Bureaucrat.hpp"
// #include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main ()
{
	Bureaucrat br("bureacrat", 5);
	Bureaucrat d ("bureacrat", 1);
	Bureaucrat anotherBr("another", 148);


	ShrubberyCreationForm  test("test");
	RobotomyRequestForm    rb("test2");
	PresidentialPardonForm prd ("test3");




	try 
	{
		test.beSigned (br);
		rb.beSigned (br);
		prd.beSigned (d);
	}
	catch (std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
		std::cout << "failed to sign form" << std::endl;
	}

	try
	{
		test.execute (br);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what() << std::endl;
	}

	// will rise an exception
	try 
	{
		test.execute (anotherBr);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}

	// will rise an exception
	anotherBr.executeForm (test);
	
	br.executeForm (test);

	try 
	{
		rb.execute (br);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}
	try 
	{
		rb.execute (br);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}

	try 
	{
		prd.execute (d);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}

	// will rise an exception
	try 
	{
		prd.execute (br);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}
}