#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main (void)
{
    Animal *animals[10] ;

	// * * copied using deep copy
	Cat A = Cat ();
	Cat B = Cat (A);
	Dog C = Dog ();
	Dog D = Dog (C);
	// example of shallow copy
	// WrongCat i;
	// WrongCat j(i);


    for  (int i = 0; i < 10;i++)
    {
        if (i < 5)
            animals[i] = new Cat ();
        else
            animals[i] = new Dog ();
    }
    for (int i = 0; i < 10;i++)
    {
        animals[i]->makeSound ();
        delete animals[i];
    }
	{
		Cat A;
		Cat B(A);
		Dog C;
		Dog D;

		C.getBrain()->setIdea ("hello world", 5);
		std::cout << " C idea : " << C.getBrain()->getIdea(5) << std::endl;
		D = C;
		std::cout << " D idea : " << D.getBrain()->getIdea(5) << std::endl;
	}
	//system ("leaks exec");
	}