#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

# include <iostream>
# include <string>

class TestClass
{
	public:
		// Constructors
		TestClass();
		TestClass(const TestClass &copy);
		
		// Destructor
		~TestClass();
		
		// Operators
		TestClass & operator=(const TestClass &assign);
		
	private:
		
};

#endif