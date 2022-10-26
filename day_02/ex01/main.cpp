#include "Fixed.hpp"


int main ()
{
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;


{
	Fixed a(101);
	Fixed b(1245.1258f);
	std::cout << "more tests " << std::endl;
	std::cout << " a as float " << a.toFloat() << std::endl;
	std::cout << " a as int " << a.toInt() << std::endl;
	std::cout << " a as fixed " << a.getRawBits () << std::endl;

	std::cout << " b as float " << b.toFloat() << std::endl;
	std::cout << " b as int " << b.toInt() << std::endl;
	std::cout << " b as fixed " << b.getRawBits () << std::endl;
}
	return (0);
}