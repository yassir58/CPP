#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Constructors
Base::Base()
{
	std::cout << "\e[0;33mDefault Constructor called of Base\e[0m" << std::endl;
}

Base::Base(const Base &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Base\e[0m" << std::endl;
}


// Destructor
Base::~Base()
{
	std::cout << "\e[0;31mDestructor called of Base\e[0m" << std::endl;
}


// Operators
Base & Base::operator=(const Base &assign)
{
	(void) assign;
	return *this;
}


Base * generate(void)
{
	Base *obj = NULL;
	int rand  = 0;

	srand (time(NULL));
	rand  = std::rand () % 3;

	std::cout << "rand : " << rand << std::endl;
	switch (rand)
	{
		case 0:
			obj = dynamic_cast<Base*> (new A ());
		break;
		case 1:
			obj = dynamic_cast<Base*> (new B ());
		break;
		case 2:
			obj = dynamic_cast<Base*> (new C ());
		break;
		default:
			break;
	}
	return (obj);
}


void identify(Base* p)
{
	A *a = NULL;
	B *b = NULL;
	C *c = NULL;

	a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "type of class is A" << std::endl;
	b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "type of class is B" << std::endl;
	c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "type of class is C" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A &a  = dynamic_cast<A&>(p);
		std::cout << "reference type is A" << std::endl;
		(void) a;
	}
	catch (std::bad_cast)
	{}

	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "reference type is B" << std::endl;
		(void) b;
	}
	catch (std::bad_cast)
	{}

	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "reference type is C" << std::endl;
		(void) c;
	}
	catch (std::bad_cast)
	{}
}

