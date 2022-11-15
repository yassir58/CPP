#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <vector>
#include <stack>
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>


template <typename T, class container=std::deque <T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack ();
		~MutantStack ();
		MutantStack (MutantStack &copy);
		MutantStack &operator= (MutantStack &assign);
		typedef typename container::iterator iterator;
		iterator begin ();
		iterator end ();
} ;

typedef MutantStack<int>::iterator Iter;

template <typename T, class container>
MutantStack<T, container>::MutantStack ()
{
	// std::cout << "\e[0;33mStack constructor \e[0m" << std::endl;
}

template <typename T, class container>
MutantStack<T, container>::~MutantStack ()
{
	// std::cout << "\e[0;31mStack destructor\e[0m" << std::endl;
}

template <typename T, class container>
MutantStack<T, container>::MutantStack (MutantStack &copy)
{
	// std::cout << "\e[0;32mStack copy constructor \e[0m" << std::endl;
	if (this != &copy)
		*this = copy;
}

template <typename T, class container>
MutantStack<T, container> &MutantStack<T, container>::operator= (MutantStack &assign)
{
	this->empty();
	for (Iter bg = assign.begin (); bg != assign.end (); ++bg)
		this->push(*bg);
	return (*this);
}


template <typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin ()
{
	return (this->c.begin ());
}

template <typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end ()
{
	return (this->c.end ());
}

#endif
