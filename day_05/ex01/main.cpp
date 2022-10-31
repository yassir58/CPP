#include "Bureaucrat.hpp"
#include "Form.hpp"




int main ()
{
	Bureaucrat test("mark schnizelnazi", 1);
	Form  testForm("random", 5, 1);
	
	std::cout << test;
	std::cout << testForm ;
	
	try 
	{
		testForm.beSigned (test);
	}
	catch (std::exception &xc)
	{
		test.signForm("test", xc);
	}
}