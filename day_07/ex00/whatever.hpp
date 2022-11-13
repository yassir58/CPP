#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_


#include <iostream>





template <class type>
void swap(type &a, type &b)
{
	type tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <class type>
type  min(type a, type b)
{
	return (a >= b ? b : a);
};

template <class type>
type  max(type a, type b)
{
	return (a <= b ? b : a);
};

#endif 