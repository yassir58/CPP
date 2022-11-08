#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
#include <cstdlib>

class Base
{
	public:
		// Constructors
		Base();
		Base(const Base &copy);
		
		// Destructor
		virtual ~Base();
		
		// Operators
		Base & operator=(const Base &assign);
		
	private:
		
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
