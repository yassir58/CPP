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
		this->value = other.getRawBits ();
}


Fixed& Fixed::operator= (const Fixed &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
		this->value = other.getRawBits ();
	return (*this);
}