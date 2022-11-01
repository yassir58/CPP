#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"



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
		Form test ("test form", 45, 200);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}

	try 
	{
		testForm.beSigned (test);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}
	test.signForm(testForm.getName (), testForm.checkIfSigned());

	try
	{
		fr.beSigned (br);
	}
	catch (std::exception &xc)
	{
		std::cout << xc.what () << std::endl;
	}
	br.signForm (fr.getName(), fr.checkIfSigned ());
}