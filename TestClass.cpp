#include "TestClass.hpp"

// Constructors
TestClass::TestClass()
{
	std::cout << "\e[0;33mDefault Constructor called of TestClass\e[0m" << std::endl;
}

TestClass::TestClass(const TestClass &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of TestClass\e[0m" << std::endl;
}


// Destructor
TestClass::~TestClass()
{
	std::cout << "\e[0;31mDestructor called of TestClass\e[0m" << std::endl;
}


// Operators
TestClass & TestClass::operator=(const TestClass &assign)
{
	(void) assign;
	return *this;
}

