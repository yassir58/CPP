#include <iostream>




namespace firstScope 
{
	void func ()
	{
		std::cout << "this is func1" << std::endl; 
	}
}

namespace secondScope 
{
	void func ()
	{
		std::cout << "this is func2" << std::endl; 
	}
}

void func ()
{
		std::cout << "this is default func" << std::endl; 
}

int main ()
{

	firstScope::func ();
	secondScope::func ();
	func ();
}