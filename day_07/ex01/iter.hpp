#ifndef ITER_HPP_
#define ITER_HPP_

#include <iostream>

template <class type>
void iter (type arr, size_t len, void (*func)(type arg, size_t indx))
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr, i);
	}
}

#endif