// class type-casting
#include <iostream>
using namespace std;

class CDummy {
    float i,j;
    public:
      float getI(void) const
      {
        return (this->i);
      }
      float getJ(void) const
      {
        return (this->j);
      }
      CDummy (float a, float b) {i = a; j = b;};
};

class CAddition {
	int x,y;
  public:
	CAddition (int a, int b) { x=a; y=b; }
  CAddition (CDummy &assign)
  {
    this->x = assign.getI();
    this->y = assign.getJ ();

  }
	int result() { return x+y;}
};



// class Base
// {
//   private:
//     int id;
//   public:
//     int getId (void) const{
//       return (this->id);
//     }
//   Base ()
//   {
//     id = 45878784 ;
//   };
//   virtual string getSecret (void) const;
// };


// class Derived: public Base
// {
//   private:
//     string secret;
//   public:
//     Derived (string secret)
//     {
//       this->secret= secret;
//     }
//     string getSecret(void) const{
//       return (this->secret);
//     }
// };

class Base {
  
  public:
    virtual void vf(){cout << "this is vf" << endl;}
  };

class Derived : public Base { };
class Test {};
class Dummy {
	// float i, j;
};


class AvecLeTemp {
	int x,y;
 	public:
	AvecLeTemp(){};
 	AvecLeTemp (int a, int b) { x=a; y=b; }
int result() { return x+y;} 
};

class AnotherTest {
	public:
		operator Test ()
		{
			return Test();
		}
};

int main () {
  // * * implicit type cast
  // short p = 485;
  // float pl = 123.14548f;
  // int a = 45;
  // char c = a;
  // int b = p;
  // short t = pl;


  // std::cout << c << std::endl;
  // std::cout << b << std::endl;
  // std::cout << t << std::endl;
  // /// explecit type cast
  // CDummy d(1.145f, 1.2453f);
  // CAddition * padd;
  // padd = (CAddition*) &d;
  // CAddition cadd = d;
  // cout << padd->result() << std::endl;
  // cout << cadd.result () << std::endl;

  // // dynamic cast
  // Base bp();

  //// base class must have a virtual function with name getString 
  //cout << bp->getSecret () << endl;

  // Derived *dp = dynamic_cast <Derived*>(&bp);

  // if (dp)
  //   cout << dp->getSecret () << endl;

  
	Base b;
	Derived d;
	Base &rf = b;
	Derived &rdf = d;
	Base A;
	Derived B;
	Test C;
	AnotherTest D;
	// AnotherTest *Y;
	AvecLeTemp  *p;
	Dummy Z;
	int *test = NULL;

	test = (int*)std::malloc (10);
	// p = (AnotherTest*)Y;
	// difference between static cast and c-type cast
	A = static_cast<Base>(B);
	//C = static_cast<Test>(A);	// no conversion 
	C = static_cast<Test>(D);
	C = (Test)D;
	p = (AvecLeTemp*) &Z;
	std::cout << p->result() << std::endl;

	Base *pb = dynamic_cast<Base*>(&d);	
	Base &pbd = dynamic_cast<Base&>(rdf);	// #1

  	pb->vf ();
  	pbd.vf ();
	Derived *pd = dynamic_cast<Derived*>(&b); 	// #2
	if (pd == NULL)
    	cout << "dynamic cast returned NULL" << endl;

	try
	{
  		Derived &dp = dynamic_cast<Derived&>(rf);
		(void)dp;
	}
	catch (std::bad_cast)
	{
		std::cout << "bad cast !" << std::endl;
	}

  return 0;
}
