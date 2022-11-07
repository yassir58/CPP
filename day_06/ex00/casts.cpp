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

	Base *pb = dynamic_cast<Base*>(&d);	
  Base *pbd = dynamic_cast<Base*>(&rdf);	// #1
  pb->vf ();
  pbd->vf ();
	Derived *pd = dynamic_cast<Derived*>(&b); 	// #2
  if (pd == NULL)
    cout << "dynamic cast returned NULL" << endl;
  Derived *dp = dynamic_cast<Derived*>(&rf);
  if (dp == NULL)
     cout << "dynamic cast returned NULL" << endl;
  typeid (dp) == typeid (&d) ? cout << "the same"<< endl : cout << "not the same";

  cout << "checking derived class type " << endl;

  

  if (typeid (b) == typeid (pd))
    cout << "same type " << endl;
  else
    cout << "not the same type" << endl;

  return 0;
}
