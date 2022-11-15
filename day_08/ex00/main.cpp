#include "easyfind.hpp"

const char *  NotFound::what () const throw ()
{
	return ("\e[0;31m << ELementNotFound >> \e[0m");
}



int main()
{
	std::vector<int> _vector_;
	std::array<int, 5> _arr_ = {5,4,3,2,1};
	std::list<int> _list_;
	srand (time(NULL));

	int elm;
	
	for (size_t i = 0; i < 5;i++)
		_vector_.push_back (i);

	for (size_t i = 0; i < 10; i++)
		_list_.push_front(rand() % 10);

	try
	{
		elm = easyfind<std::vector<int> >(_vector_, 2);
		std::cout << "Element found : " << elm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		elm = easyfind<std::array<int, 5> >(_arr_, 9);
		std::cout << "Element found in index : " << elm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		elm = easyfind <std::list <int> > (_list_, 5);
		std::cout << "Element found : " << elm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
