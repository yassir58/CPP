#include "Fixed.hpp"

int Fixed::getRawBits (void) const
{
	// std::cout<<"getRawBits member function called"<<std::endl;
	return (this->value);
}

void Fixed::setRawBits (int value)
{
	this->value = value;
}

Fixed::Fixed ()
{
	// std::cout << "Default constructor called" << std::endl;
	this->setRawBits (0);
}

Fixed::~Fixed ()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &other)
{
	// std::cout<<"Copy constructor called"<<std::endl;
	if (this != &other)
		this->value = other.value;
}


Fixed& Fixed::operator= (const Fixed &other)
{
	// std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

Fixed::Fixed (const int number)
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits (std::roundf (number * (1 << Fixed::bits)));
}

Fixed::Fixed (const float number)
{
	// std::cout << "Float constructor called" << std::endl;
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

Fixed Fixed::operator+ (Fixed n1)
{
	Fixed res;
	res.value  = this->value + n1.value;
	return (res);
}

Fixed Fixed::operator- (Fixed n1)
{
	Fixed res;
	res.value = this->value - n1.value;
	return (res);
}

Fixed Fixed::operator* (Fixed n1)
{
	Fixed res = Fixed ((this->toFloat () * n1.toFloat ()));
	return (res);
}

Fixed Fixed::operator/ (Fixed n1)
{
	Fixed res = Fixed ((this->toFloat () / n1.toFloat ()));
	return (res);
}

Fixed& Fixed::operator-- (void)
{
	
	--(this->value);
	return (*this);
}

Fixed Fixed::operator-- (int dummyArg)
{
	(void)dummyArg;
	Fixed cpy;

	cpy = *this;
	(this->value)--;
	return (cpy);
}

Fixed& Fixed::operator++ (void)
{
	(this->value)++;
	return (*this);
}


Fixed Fixed::operator++ (int dummyArg)
{
	(void)dummyArg;
	Fixed cpy;
	cpy = *this;
	(this->value)++;
	return (cpy);
}

std::ostream& operator << (std::ostream& o,  Fixed const &num)
{
    o << num.toFloat ();
    return o;
}

int Fixed::operator!= (Fixed &n1)
{
	if (this->value != n1.value)
		return (1);
	return (0);
}

int Fixed::operator== (Fixed &n1)
{
	if (this->value == n1.value)
		return (1);
	return (0);
}

int Fixed::operator>= (Fixed &n1)
{
	if (this->value >= n1.value)
		return (1);
	return (0);
}

int Fixed::operator<= (Fixed &n1)
{
	if (this->value <= n1.value)
		return (1);
	return (0);
}

int Fixed::operator> (Fixed &n1)
{
	if (this->value > n1.value)
		return (1);
	return (0);
}
int Fixed::operator< (Fixed &n1)
{
	if (this->value < n1.value)
		return (1);
	return (0);
}

Fixed &Fixed::min (Fixed &n1, Fixed &n2)
{
	return (n1 > n2 ? n1 : n2);
} 

Fixed &Fixed::max (Fixed &n1, Fixed &n2)
{
	return (n1 < n2 ? n1 : n2);
}

Fixed const &Fixed::min (Fixed const &n1, Fixed const &n2)
{
	return ((Fixed &)n1 > (Fixed &)n2 ? n2 : n1);
} 

Fixed const &Fixed::max (Fixed const &n1, Fixed const &n2)
{
	return ((Fixed &)n1 > (Fixed &)n2 ? n1 : n2);
}