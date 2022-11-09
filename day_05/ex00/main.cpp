#include "Bureaucrat.hpp"




int main ()
{
	Bureaucrat A("A", 1);
	std::cout << A << std::endl;

	std::cout << "name  : " << A.getName() << std::endl;
	std::cout << "grade : " << A.getGrade() << std::endl;
	try 
	{
		A.decrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
		std::cout << "trying to decrement grade failed" << std::endl;
	}
	std::cout << A << std::endl;

	try 
	{
		std::cout << "grade : " << A.getGrade() << std::endl;
		A.incrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << "trying to increment grade failed" << std::endl;
		std::cout << xc.what () << std::endl;
	}
	std::cout << "grade : " << A.getGrade() << std::endl;
	std::cout << A << std::endl;
	try 
	{
		A.incrementGrade ();
	}
	catch (std::exception &xc)
	{
		std::cout << "trying to increment grade failed" << std::endl;
		std::cout << xc.what () << std::endl;
	}
	std::cout << A << std::endl;

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