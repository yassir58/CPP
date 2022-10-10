#include "Fixed.hpp"

void test_equality (Fixed num1, Fixed num2)
{
	if (num1 == num2)
		std::cout << num1 << " ==  true " << num2 << std::endl;
	else
		std::cout << num1 << " == false " << num2 << std::endl; 
}

void test_difference (Fixed num1, Fixed num2)
{
	if (num1 != num2)
		std::cout << num1 << " != true " << num2 << std::endl;
	else
		std::cout << num1 << " != false " << num2 << std::endl; 
}

void test_bte (Fixed num1, Fixed num2)
{
	if (num1 >= num2)
		std::cout << num1 << " >= true " << num2 << std::endl;
	else
		std::cout << num1 << " >= false " << num2 << std::endl; 
}

void test_lte (Fixed num1, Fixed num2)
{
	if (num1 <= num2)
		std::cout << num1 << " <= true " << num2 << std::endl;
	else
		std::cout << num1 << " <= false " << num2 << std::endl; 
}
void test_lt (Fixed num1, Fixed num2)
{
	if (num1 < num2)
		std::cout << num1 << " < true " << num2 << std::endl;
	else
		std::cout << num1 << " < false  " << num2 << std::endl; 
}

void test_bt (Fixed num1, Fixed num2)
{
	if (num1 > num2)
		std::cout << num1 << " > true " << num2 << std::endl;
	else
		std::cout << num1 << " > false " << num2 << std::endl; 
}

void ar_plus_test (Fixed n1, Fixed n2, Fixed res)
{
	if ((n1 + n2) == res)
		std::cout << n1 << " + " << n2 << " right " << std::endl;
	else
		std::cout << n1 << " + " << n2 << " wrong " << std::endl;
}


void ar_minus_test (Fixed n1, Fixed n2, Fixed res)
{
	if ((n1 - n2) == res)
		std::cout << n1 << " - " << n2 << " right " << std::endl;
	else
		std::cout << n1 << " - " << n2 << " wrong " << std::endl;
}

void ar_mult_test (Fixed n1, Fixed n2, Fixed res)
{
	std::cout <<(n1 * n2) << " ";
	if ((n1 * n2) == res)
		std::cout << n1 << " * " << n2 << " right " << std::endl;
	else
		std::cout << n1 << " * " << n2 << " wrong " << std::endl;
}

void ar_div_test (Fixed n1, Fixed n2, Fixed res)
{
	std::cout <<(n1 / n2) << " ";
	if ((n1 / n2) == res)
		std::cout << n1 << " / " << n2 << " right " << std::endl;
	else
		std::cout << n1 << " / " << n2 << " wrong " << std::endl;
}

int main ()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed num1(45);
	Fixed num2(45.0f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << " ____________ comparison operators tests _________________ " << std::endl;
	test_equality (Fixed (48.4822f) , Fixed (48.4823f));
	test_equality (Fixed (0), Fixed (0.00000f));
	test_equality (Fixed (0), Fixed (0.00001f));
	test_equality (Fixed (0.0001f), Fixed (0.00001f));
	test_equality (Fixed (0.2454f), Fixed (0.2511f));
	test_equality (Fixed (0.2345f), Fixed (0.2345f));
	test_difference (Fixed (484.122f), Fixed (484.151f));
	test_difference (Fixed (484.122f), Fixed (484.122f));
	test_difference (num1, num2);
	test_lt (Fixed (0.124f), Fixed (0.458f));
	test_lt (Fixed (0.924f), Fixed (0.458f));
	test_lte (Fixed (0.124f), Fixed (0.458f));
	test_lte (Fixed (0.924f), Fixed (0.458f));
	test_bt ( Fixed (48.4822f), Fixed (48));
	test_bte ( Fixed (49), Fixed (48));
	std::cout << " ____________ arithmitic operators tests _________________ " << std::endl;
	ar_plus_test (Fixed (2), Fixed (2), Fixed (4));
	ar_plus_test (Fixed (4), Fixed (6), Fixed (10.00f));
	ar_plus_test (Fixed (2), Fixed (2.0000f), Fixed (4));
	ar_plus_test (Fixed (2), Fixed (188484), Fixed (188486));
	ar_plus_test (Fixed (1.5000f), Fixed (1.5000f), Fixed (3));
	ar_minus_test (Fixed (4), Fixed (2), Fixed (2));
	ar_minus_test (Fixed (12.45f), Fixed (6.45f), Fixed (6));
	ar_minus_test (Fixed (0.000f), Fixed (0.0f), Fixed (0));
	ar_minus_test (Fixed (4.20484f), Fixed (4.11210f), Fixed (0.08984f));
	ar_mult_test (Fixed (2), Fixed (2), Fixed (4));
	ar_mult_test (Fixed (2), Fixed (5), Fixed (10.00f));
	ar_mult_test (Fixed (2), Fixed (2.0000f), Fixed (4));
	ar_mult_test (Fixed (1.15f), Fixed (2.45f), Fixed (2.8125f));
	ar_div_test (Fixed (2.4f), Fixed (1.45f), Fixed (1.6551f));
	ar_div_test (Fixed (1), Fixed (3), Fixed (0.33333f));
	std::cout << Fixed::min( a, b ) << std::endl;

	return (0);
}