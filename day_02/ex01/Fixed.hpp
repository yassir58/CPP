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
		~Fixed ();
};

std::ostream& operator << (std::ostream& o,  Fixed const &num);

#endif