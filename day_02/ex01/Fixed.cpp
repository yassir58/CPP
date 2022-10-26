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

Fixed::Fixed (const int number)
{
	std::cout << "\e[0;32mInt constructor called\e[0m" << std::endl;
	setRawBits (number * (1 << Fixed::bits));
}

Fixed::Fixed (const float number)
{
	std::cout << "\e[0;32mFloat constructor called\e[0m" << std::endl;
	setRawBits (std::roundf (number * (1 << Fixed::bits)));
}

int Fixed::toInt (void) const
{
	return (std::roundf (this->value / (1 << Fixed::bits)));
}

float Fixed::toFloat (void) const 
{
	float res = (float)this->value / (float)(1 << Fixed::bits);
	return (res);
}

std::ostream& operator << (std::ostream & o,Fixed const  &num)
{
    o << num.toFloat ();
    return o;
}