#include <iostream>

class B {};
class D : public B {};
class X {};

// polymorphic class
class C 
{
	public:
		virtual ~C (){};
};

class E: public C {
	public:
		E (){};
};


int main()
{
	// the difference between c-type cast and static_cast 
  D* d = new D;
  B* b = static_cast<B*>(d);
  
  // conversion from Base to Derived works, not like dynamic cast
  D* d1 = static_cast<D*>(b);
  //D* d2 = dynamic_cast<D*>(new X); // failed when the rvalue not a polymorphic type
  E* d3 = dynamic_cast<E*>(new C);
  if (!d3)
	std::cout << "d3 = NULL" << std::endl;
C* c1 = dynamic_cast<C*>(new E);
	if (!c1)
		std::cout << "c1 = NULL" << std::endl;
	else
		std::cout << "c1 != NULL" << std::endl;		

   // this works
  	//X* x = static_cast<X*>(d); // ERROR - Won't compile
	//X* t = (d); // implicit cast

	// implicit conversion fail when the conversion preformed on two uncompatible types ,
	// without checking if two objects are related or not
	X* x = (X*)(d);


	/// casting fundamental data types

	{
		// implicit type cast
		float a  = 1.148456f;
		int b = a;

		// data loss we lose the precesion of variable a
		std::cout << "a: " << a <<  std::endl;
		std::cout << "B: " << b << std::endl;
		a = b;
		std::cout << "a: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
	}

	{
		/// c-type cast
		char a  = 45;
		int *b = NULL;


		//b = static_cast<int *>(&a);
		b = (int *)(&a);
	}

	{
		int *n = new int (9800);
		char c = 72;
		char p = 38;

		char *s = reinterpret_cast<char *>(n);

		std::cout << "int pointer : " << n << std::endl;
		std::cout << "string pointer : " << &s << std::endl;
		std::cout << "string value : " << s << std::endl;
		std::cout << "c : " << c << std::endl;
		std::cout << "p : " << p << std::endl;
	}
	


	(void)x;
	(void)d;
	(void)b; 
	(void)d1;
  return 0;
}
