#include "Array.hpp"




int main ()
{
	std::string ar[5] = {"hello world", "test", "shdj", "1334", "opop"};
	// Array<std::string> t(5);

	// for (size_t i = 0; i < 5; i++)
	// 	t.setElement(ar[i], i);
	Array<int> arr;
	Array<int> test(5);
	// Array <std::string> strs(ar);

	std::cout << arr.size () << std::endl;
	test.print();
	// strs.print ();
	// t.print ();
	// std::cout << t.getElement(2) << std::endl;
	return (0);
}