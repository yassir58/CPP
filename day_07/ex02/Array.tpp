#include "Array.hpp"


template <class T>
Array<T>::Array ()
{
	std::cout << "\e[0;33m Array constructor \e[0m" << std::endl;
	this->_ptr = NULL;
	this->_size = 0;
}


template <class T>
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



template <class T>
Array<T>::Array (Array<T> const &copy)
{
	this->_size = copy.size ();
	std::cout << "_______" << this->_ptr << std::endl;
	this->_ptr = new T (copy._size);
	std::cout << this->_ptr << std::endl;
}

template <class T>
Array<T> & Array<T>::operator = (const Array<T> &assign)
{
	// if (this->_ptr && this->size () > 0)
	// 	delete _ptr;
	this->_ptr = new T(assign._size);
	std::cout << this->_ptr << std::endl;
	return (*this);
}

template <class T>
T* Array<T>::AllocatePtr (size_t size)
{
	T *ptr = NULL;
	try
	{
		ptr = new T (size);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	return (NULL);
}

template <class T>
Array<T>::~Array ()
{
	std::cout << "\e[0;31m Array destructor \e[0m" << std::endl;
	if (this->_ptr && this->size () > 0)
		delete _ptr;
} 

template <class T>
size_t Array<T>::size () const
{
	return (this->_size);
}


template <class T>
void Array<T>::print () const
{
	if (this->_ptr)
	{
		for (size_t i  = 0;i < this->_size; i++)
			std::cout << this->_ptr[i] ;
		std::cout << std::endl;
	}
}


template <class T>
void Array<T>::setElement (T elm, size_t indx)
{
	if (this->_ptr && indx <= this->_size - 1)
		this->_ptr[indx] = elm;
}

template<class T>
T Array<T>::getElement (size_t indx) const
{
	if (this->_ptr && indx <= this->_size - 1)
		return (this->_ptr[indx]);
	return (0);
}

