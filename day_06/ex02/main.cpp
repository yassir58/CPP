#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



int main ()
{
	Base * test = generate();
	identify (test);

	Base * test2 = generate();
	Base &ref = *test2;

	identify (ref);
	delete test;
	delete test2;
	// system("leaks exec");
	return (0);
}
