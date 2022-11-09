#include "iter.hpp"



void multiply (int *a, size_t indx)
{
	int b = a[indx] * 2;
	std::cout << b << std::endl;
}


void cappitalize (std::string *str, size_t indx)
{
	int i = 0;
	while (str[indx][i])
	{
		std::cout << (char)toupper(str[indx][i]) ;
		i++;
	}
	std::cout << std::endl;
}


int main ()
{
	int intArr [5] = {1,2,3,4,5};
	std::string arr[4] = {"hello world", "test", "abc"};

	::iter <int*>(intArr, 5, multiply);
	::iter <std::string*>(arr, 3, cappitalize);
	return (0);
}