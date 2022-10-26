#include <iostream>

class Test
{
	private:
		int a;
		std::string str;
	public:
		void sayHello ()
		{
			std::cout << "hello world" << std::endl;
		};
	Test ()
	{
		std::cout << "Test Constructed" << std::endl;
	};
	Test(const Test &assign)
	{
		std::cout << "Test copied" << std::endl;
	}
	~Test ()
	{
		std::cout << "Test Destructed" << std::endl;
	}
};

namespace firstScope 
{
	void func ()
	{
		std::cout << "this is func1" << std::endl; 
	}
}


void TestFunction (Test a)
{
	a.sayHello ();
}

void TestRef (Test &a)
{
	a.sayHello ();
}

namespace secondScope 
{
	void func ()
	{
		std::cout << "this is func2" << std::endl; 
	}
}

void func ()
{
		std::cout << "this is default func" << std::endl; 
}

int main ()
{

	// firstScope::func ();
	// secondScope::func ();
	// Test a;

	// std::cout << a.getA (45) << std::endl;
	// func ();

	int x = 45;
	int &ref = x;
	double a = 0.1f;
	double b = 0.2f;
	double c = 0.3f;

	ref++;

	std::cout << &x << " : " << &ref << std::endl;
	std::cout << x << std::endl ;
	std::cout << a << " " <<  b << " " << c << std::endl;
	std::cout << a + b + c << std::endl;
	std::cout << (1 << 8) << std::endl;
	std::cout << sizeof (Test) << std::endl;
	std::cout << sizeof (std::string) << std::endl;
}