#include "Fixed.hpp"


int Fixed::getRawBits (void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->value);
}

void Fixed::setRawBits (int value)
{
	this->value = value;
}

Fixed::Fixed ()
{
	std::cout << "\e[0;33mDefault constructor called\e[0m" << std::endl;
	this->setRawBits (0);
}

Fixed::~Fixed ()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

Fixed::Fixed (const Fixed &other)
{
	std::cout<<"\e[0;34mCopy constructor called\e[0m"<<std::endl;
	if (this != &other)
		this->value = other.getRawBits ();
}


Fixed& Fixed::operator= (const Fixed &other)
{
	std::cout<<"\e[0;34mCopy assignment operator called\e[0m"<<std::endl;
	if (this != &other)
		this->value = other.getRawBits ();
	return (*this);
}