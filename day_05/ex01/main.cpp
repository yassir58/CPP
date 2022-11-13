#include "Bureaucrat.hpp"
#include "Form.hpp"


int main ()
{
	Bureaucrat a("A", 1);
	Form  r("random", 5, 1);
	Bureaucrat b("B", 90);
	Form c ("C", 6, 8);
	
	std::cout << a;
	std::cout << r ;
	

	try
	{
		// exception thrown in constructor
		Form a ("test form", 45, 200);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}

	// will not throw an exception
	try 
	{
		r.beSigned (a);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}	
	a.signForm(r);

	// will throw an exception 
	try
	{
		c.beSigned (b);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}
	b.signForm (c);


	// uncaught exception
	//fr.beSigned (b);
	return (0);
}