#include "Bureaucrat.hpp"




int main ()
{
	Bureaucrat test("mark schnizelnazi", 1);
	std::cout << test;

	try 
	{
		test.decrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
		std::cout << "trying to decrement grade" << std::endl;
	}
	std::cout << test;

	try 
	{
		test.incrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
		std::cout << "trying to increment grade" << std::endl;
	}
	std::cout << test;
	try 
	{
		test.incrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
		std::cout << "trying to increment grade" << std::endl;
	}
	std::cout << test;

	try
	{	
		Bureaucrat random ("random", 240);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
		std::cout << "caught in constructor" << std::endl;
	}

}