#include "Span.hpp"


#define MAX_SIZE 100000
#define SMAX_SIZE 7


int main ()
{
	Span sp = Span(5);
	Span test(MAX_SIZE);
	Span smallTest(SMAX_SIZE);
	Span AnotherSpan(SMAX_SIZE);
	Span AssignSpan;
	Iter max_val ;
	Iter min_val ;

	int val[] = {1,2,3,5,9,11,12};
	srand (time(NULL));


	/// simple tests
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printSpan ();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "shortes span expected : 2  => \e[0;32m" << sp.shortestSpan() << "\e[0m" <<  std::endl;
	std::cout << "longest span expected : 14 => \e[0;32m" <<  sp.longestSpan() << "\e[0m" <<  std::endl;
	

	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		int r = rand() % 100000;
		test.addNumber (r);
	}

	//test.printSpan ();
	try
	{
		test.addNumber (7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
	// max_val = std::max_element (start, end);
	// min_val = std::min_element (start, end);

	// std::cout << "min value : " << *min_val << std::endl;
	// std::cout << "max value : " << *max_val << std::endl;

	for (size_t i = 0; i < SMAX_SIZE; i++)
	{
		smallTest.addNumber (val[i]);
	}
	//smallTest.printSpan ();
	//test.printSpan ();
	std::cout << "shortes span expected : 1  => \e[0;32m" << smallTest.shortestSpan() << "\e[0m" <<  std::endl;
	std::cout << "longest span expected : 4  => \e[0;32m" <<  smallTest.longestSpan() << "\e[0m" <<  std::endl;

	std::cout << "shortes span expected  => \e[0;32m" << test.shortestSpan() << "\e[0m" <<  std::endl;
	std::cout << "longest span expected  => \e[0;32m" <<  test.longestSpan() << "\e[0m" <<  std::endl;
	
	Iter start= smallTest.getSpanVector().begin();
	Iter end = 	smallTest.getSpanVector().end ();

	// if (*start == *end)
	// 	std::cout << "equal" << std::endl;
	// std::cout << "start  : " << *start << std::endl;
	// std::cout << "end : " << *end << std::endl;
	std::cout << "\e[0;33m testing range iterator \e[0m" << std::endl;
	try
	{
		AnotherSpan.AddRange (AnotherSpan.getSpanVector().end(), start, end, smallTest.getMax ());
		AnotherSpan.printSpan ();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\e[0;33m Testing copy and assignement operator \e[0m" << std::endl;
	Span copySpan(sp);

	AssignSpan = sp;

	copySpan.printSpan ();
	AssignSpan.printSpan ();
	//system ("leaks exec");
	return (0);
}
