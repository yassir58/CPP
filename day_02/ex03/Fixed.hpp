#ifndef _FIXED_HPP
#define _FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	private:
		int value;
		static const int bits = 8;

	public:
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat (void) const;
		int toInt (void) const;
		Fixed ();
		Fixed (const int number);
		Fixed (const float number);
		Fixed (const Fixed &other);
		Fixed& operator=(const Fixed &other);
		Fixed operator- (Fixed n1);
		Fixed operator+ (Fixed n1);
		Fixed operator* (Fixed n1);
		Fixed operator/ (Fixed n1);
		Fixed& operator-- (void);
		Fixed& operator++ (void);
		Fixed operator-- (int dummyArg);
		Fixed operator++ (int dummyArg);
		int operator== (Fixed &other);
		int operator>= (Fixed &other);
		int operator<= (Fixed &other);
		int operator> (Fixed &other);
		int operator< (Fixed &other);
		int operator!= (Fixed &other);
		static Fixed &min (Fixed &n1, Fixed &n2);
		static Fixed &max (Fixed &n1, Fixed &n2);
		static Fixed const &min (Fixed const &n1, Fixed const &n2);
		static Fixed const &max (Fixed const &n1, Fixed const &n2);
		// * * postfix operator has dummy parameter
		// * * prefix operator has no parameters 
		~Fixed ();
};

std::ostream& operator << (std::ostream& o,  Fixed const &num);


#endif