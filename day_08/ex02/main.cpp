#include "MutantStack.hpp"





int main ()
{
	MutantStack<int> test;

	test.push (45);
	test.push (10);
	test.push (98);

	std::cout << "\e[0;33m testing stack iterators \e[0m" << std::endl;
	for (Iter bg = test.begin (); bg != test.end();++bg)
		std::cout << *bg << std::endl;
	std::cout << "\e[0;32m testing copy constructor \e[0m" << std::endl;
	MutantStack<int> cp(test);

	for (Iter bg = cp.begin (); bg != cp.end();++bg)
		std::cout << *bg << std::endl;
	std::cout << "\e[0;32m testing copy assignement \e[0m" << std::endl;
	MutantStack<int> assign;

	assign = cp;
	for (Iter bg = assign.begin (); bg != assign.end();++bg)
		std::cout << *bg << std::endl;
	std::cout << "\e[0;32m MutantStack tests \e[0m" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\e[0;32m standard list tests \e[0m" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	//system ("leaks exec");
	return (0);
}
