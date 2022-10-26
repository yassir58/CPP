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



class Bird 
{
	std::string name;
	int age;
	public :
		void sayHi (void)
		{
			std::cout << "hello world" << std::endl;
			std::cout << this->name << std::endl;
			std::cout << this->age << std::endl;
		}
	Bird ():name ("frida"), age (20)
	{

	}
	Bird (std::string name, int age):name (name), age (age)
	{
	}
};

class Chiken : public Bird
{
	std::string name;
	int age;
	int road_crossed;
	public:
		std::string religion;
		void greet ()
		{
			std::cout << "hi good by" << std::endl;
			std::cout << this->name << std::endl;
			std::cout << this->age << std::endl;
			std::cout << this->road_crossed << std::endl;
		}
	Chiken (std::string name, int age):name (name), age (age), road_crossed (0), religion("muslim")
	{
	}
};

int main ()
{

	// firstScope::func ();
	// secondScope::func ();
	// Test a;

	// // std::cout << a.getA (45) << std::endl;
	// // func ();

	// int x = 45;
	// int &ref = x;
	// double a = 0.1f;
	// double b = 0.2f;
	// double c = 0.3f;

	// ref++;

	// std::cout << &x << " : " << &ref << std::endl;
	// std::cout << x << std::endl ;
	// std::cout << a << " " <<  b << " " << c << std::endl;
	// std::cout << a + b + c << std::endl;
	// std::cout << (1 << 8) << std::endl;
	// std::cout << sizeof (Test) << std::endl;
	// std::cout << sizeof (std::string) << std::endl;

	Chiken frida = Chiken ("tach", 10);

	Bird  *tachChiken = &frida;

	std::cout << "_______________ chiken _____________________";
	std::cout << frida.religion << std::endl;
	frida.greet ();
	
	std::cout << "_______________ Bird _____________________";
	tachChiken->sayHi ();
	std::cout << tachChiken->religion << std::endl;
	//std::cout << tachChiken.religion << std::endl; 
}