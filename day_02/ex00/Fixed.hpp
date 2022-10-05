#ifndef _FIXED_HPP
#define _FIXED_HPP

#include <iostream>



class Fixed 
{
	private:
		int value;
		static const int bits = 8;

	public:
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed ();
		Fixed (const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed ();
};




#endif