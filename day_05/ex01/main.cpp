#include "Bureaucrat.hpp"
#include "Form.hpp"


int main ()
{
	Bureaucrat test("mark schnizelnazi", 1);
	Form  testForm("random", 5, 1);
	Bureaucrat br("random bureaucrat", 90);
	Form fr ("form1", 6, 8);
	
	std::cout << test;
	std::cout << testForm ;
	

	try
	{
		// exception thrown i constructor
		Form test ("test form", 45, 200);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}

	// will not throw an exception
	try 
	{
		testForm.beSigned (test);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}	
	test.signForm(testForm);

	// will throw an exception 
	try
	{
		fr.beSigned (br);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}
	br.signForm (fr);


	// uncaught exception
	//fr.beSigned (br);
	return (0);
}