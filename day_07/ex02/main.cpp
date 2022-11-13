#include "Array.hpp"




int main ()
{
	Array <int>list;
	Array <int>ar1(100);
	size_t indx = 0;

	std::cout << "list Size : " << list.size() << std::endl;
	std::cout << list.getElement(indx) << std::endl;
	list.setElement (150, 0);
	for (size_t i = 0; i < 100; i++)
		ar1.setElement(i,i);
	ar1.print ();
	Array <int>ar2(ar1);

	// std::cout << "ar1 address : " << ar1._ptr << std::endl;
	// std::cout << "ar2 address : " << ar2._ptr << std::endl;
	// ar2.print ();
	return (0);
}