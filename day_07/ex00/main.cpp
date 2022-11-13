#include "whatever.hpp"


class Test 
{
	private:
		int id;
	public:
		Test (int id)
		{
			this->id = id;
		};
		Test (Test &copy)
		{
			this->id = copy.id;
		};
		Test &operator=(Test &assign)
		{
			this->id = assign.id;
			return (*this);
		}
		int getId (void) const
		{
			return (this->id);
		}
};

int main ()
{
	int a = 2;
	int b = 3;
	Test A(12498);
	Test B (78976); 

	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	std::cout << "a id :" << A.getId () << std::endl;
	std::cout << "b id :" << B.getId () << std::endl;
	::swap<Test> (A, B);
	std::cout << "a id :" << A.getId () << std::endl;
	std::cout << "b id :" << B.getId () << std::endl;
	return 0;
}