#ifndef ARRAY_HPP_
#define ARRAY_HPP_


#include <iostream>

template <typename T> class Array
{
	private:
		T *_ptr;
		size_t _size;
	public :
		Array ();
		Array (size_t size);
		// Array (T arr[]);
		// T operator= (T &arr);
		// T operator[] (T &arr);
		// T getElement (int indx) const;
		void    print (void)  const; // testing
		void 	setElement (T elm, size_t indx);
		T		getElement (size_t indx) const;
		size_t  size (void) const;

};


template <typename T>
Array<T>::Array ()
{
	this->_ptr = new T();
	this->_size = 0;
	std::cout << "\e[0;33m Array constructor \e[0m" << *this->_ptr << std::endl;
}

template <typename T>
Array<T>::Array (size_t size)
{
	this->_ptr = new T(size);
	this->_size = size;
	// for (size_t i  = 0;i < this->_size; i++)
	// 	this->_ptr[i] = 0;
	
	// std::cout << "\e[0;33m Array constructor " << *this->_ptr << std::endl;
}


// template <typename T>
// Array<T>::Array (T arr[])
// {
// 	this->_size = arr.size ();
// 	this->_ptr = new T(this->_size);
// 	for (size_t  i = 0; i < this->_size; i++)
// 	{
// 		this->_ptr[i] = arr._ptr[i];
// 	}
// }

template <typename T>
size_t Array<T>::size () const
{
	return (this->_size);
}


template <typename T>
void Array<T>::print () const
{
	for (size_t i  = 0;i < this->_size; i++)
		std::cout << this->_ptr[i] ;
	std::cout << std::endl;
}


template <typename T>
void Array<T>::setElement (T elm, size_t indx)
{
	this->_ptr[indx] = elm;
}

template<typename T>
T Array<T>::getElement (size_t indx) const
{
	// if (indx > this->_size - 1)
	// 	throw std::exception;
	return (this->_ptr[indx]);
}

#endif