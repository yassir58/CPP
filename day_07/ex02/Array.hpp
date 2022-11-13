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
		Array (Array &arr);
		~Array ();
		Array & operator= (Array const &assign);
		T & operator[] (Array &arr);
		T getElement (int indx) const;
		void    print (void)  const; // testing
		void 	setElement (T elm, size_t indx); // testing
		T		getElement (size_t indx) const; // testing
		size_t  size (void) const;

};


template <typename T>
Array<T>::Array ()
{
	std::cout << "\e[0;33m Array constructor \e[0m" << std::endl;
	this->_ptr = NULL;
	this->_size = 0;
}


template <typename T>
Array<T>::Array (size_t size)
{
	std::cout << "\e[0;33m Array parameter constructor \e[0m" << std::endl;
	try
	{
		this->_ptr = new T(size);

		for (size_t i = 0; i < size; i++)
			this->_ptr[i] = 0;
		this->_size = size;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


template <typename T>
Array<T>::Array (Array &arr)
{
	std::cout << "\e[0;32m Array copy constructor \e[0m" << std::endl;

	_size = arr._size;
	this->_ptr = new T;
	std::cout << this->_ptr << std::endl;
}

template <typename T>
Array<T> & Array<T>::operator= (Array const &assign)
{
	std::cout << "\e[0;32m Array copy assignement operator \e[0m" << std::endl;
	if (this->_ptr)
	{
		delete this->_ptr;
	}
	try
	{
		this->_ptr = new T(assign._size);

		for (size_t i = 0; i < assign._size; i++)
			this->_ptr[i] = assign._ptr[i];
		this->_size = assign._size;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (*this);
}

template <typename T>
Array<T>::~Array ()
{
	std::cout << "\e[0;31m Array destructor \e[0m" << std::endl;
	// if (this->_ptr)
	// 	delete _ptr;
} 

template <typename T>
size_t Array<T>::size () const
{
	return (this->_size);
}


template <typename T>
void Array<T>::print () const
{
	if (this->_ptr)
	{
		for (size_t i  = 0;i < this->_size; i++)
			std::cout << this->_ptr[i] ;
		std::cout << std::endl;
	}
}


template <typename T>
void Array<T>::setElement (T elm, size_t indx)
{
	if (this->_ptr)
		this->_ptr[indx] = elm;
}

template<typename T>
T Array<T>::getElement (size_t indx) const
{
	if (this->_ptr && indx <= this->_size - 1)
		return (this->_ptr[indx]);
	return (0);
}

#endif