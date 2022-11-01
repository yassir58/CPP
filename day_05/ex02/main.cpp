#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main ()
{
	ShrubberyCreationForm test("test");
	Bureaucrat br("bureacrat", 5);
	Bureaucrat d ("bureacrat", 1);
	//Bureaucrat anotherBr("another", 148);
	RobotomyRequestForm rb ("test2");
	PresidentialPardonForm prd ("test3");

	test.beSigned (br);
	rb.beSigned (br);
	prd.beSigned (d);
	try 
	{
		test.execute (br);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what() << std::endl;
	}

	// try 
	// {
	// 	test.execute (anotherBr);
	// }
	// catch (std::exception & xc)
	// {
	// 	std::cout << xc.what () << std::endl;
	// }

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

	try 
	{
		prd.execute (br);
	}
	catch (std::exception & xc)
	{
		std::cout << xc.what () << std::endl;
	}
}