#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iterator> // for iterators
#include <vector>
#include <iostream>
#include <array>
#include <algorithm>
#include <list>


class NotFound : public std::exception
{
	public:
		virtual const char * what () const throw ();
};

template <typename T> 
int easyfind (T Container, int i)
{
	typedef typename T::iterator Iter;
	Iter start = Container.begin (); 
	Iter end  = Container.end ();
	Iter indx = std::find (start, end, i);

	if (indx != end)
		return (*indx);
	throw NotFound();
}


#endif
