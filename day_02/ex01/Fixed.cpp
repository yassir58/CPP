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
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits (0);
}

Fixed::~Fixed ()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	if (this != &other)
		this->value = other.value;
}


Fixed& Fixed::operator= (const Fixed &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

Fixed::Fixed (const int number)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits (std::roundf (number * (1 << Fixed::bits)));
}

Fixed::Fixed (const float number)
{
	std::cout << "Float constructor called" << std::endl;
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