#include <iostream>


class xcept : public std::exception
{
	virtual const char* what(void) const throw ();
};

const char * xcept::what (void) const throw ()
{
	return ("\e[0;31m << Exception >> \e[0m");
}

int main ()
{
	xcept a;
	try 
	{
		throw (a);
		std::cout << "after throw " << std::endl;
	}
	catch (int i)
	{
		std::cout << "handle for int" << std::endl;
	}
	catch (std::exception &xec)
	{
		std::cout << xec.what () << std::endl;
	}
	std::cout << "after exception" << std::endl;
}