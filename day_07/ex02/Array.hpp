#ifndef ARRAY_HPP_
#define ARRAY_HPP_


#include <iostream>

template <class T> class Array
{
	private:
		T *_ptr;
		size_t _size;
	public :
		Array ();
		Array (size_t size);
		Array (const Array<T>  &arr);
		~Array ();
		Array & operator= (const Array<T>  &assign);
		T & operator[] (Array &arr);
		T getElement (int indx) const;
		void    print (void)  const; // testing
		void 	setElement (T elm, size_t indx); // testing
		T		getElement (size_t indx) const; // testing
		T* AllocatePtr (size_t size);
		size_t  size (void) const;

};


#include "Array.tpp"

#endif