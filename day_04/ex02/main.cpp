#include "Animal_A.hpp"
#include "Cat.hpp"
#include "Dog.hpp"




int main (void)
{
	// abstract class can not be instanciated 
	//const Animal_A* ABS = new Animal_A ();
	const Animal_A* j = new Dog();
	const Animal_A* i = new Cat();


	std::cout << "type : " << j->getType() << " " << std::endl;
	std::cout << "type : " <<  i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete i;
	delete j;
	// system ("leaks exec");
}