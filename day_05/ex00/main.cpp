#include "Bureaucrat.hpp"




int main ()
{
	Bureaucrat test("mark schnizelnazi", 1);
	std::cout << test;

	std::cout << "name  : " << test.getName() << std::endl;
	std::cout << "grade : " << test.getGrade() << std::endl;
	try 
	{
		test.decrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
		std::cout << "trying to decrement grade failed" << std::endl;
	}
	std::cout << test;

	try 
	{
		std::cout << "grade : " << test.getGrade() << std::endl;
		test.incrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << "trying to increment grade failed" << std::endl;
		std::cout << xc.what () << std::endl;
	}
	std::cout << "grade : " << test.getGrade() << std::endl;
	std::cout << test;
	try 
	{
		test.incrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << "trying to increment grade failed" << std::endl;
		std::cout << xc.what () << std::endl;
	}
	std::cout << test;

	try
	{	
		Bureaucrat random ("random", 240);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
		std::cout << "instantiate a Bureaucrat using an invalid grade" << std::endl;
	}

}