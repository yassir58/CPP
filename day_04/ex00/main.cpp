#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main (void)
{

// animal instantiation test
const Animal* meta = new Animal();

// subtype polymorphism tests
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* wr = new WrongCat ();
const WrongCat *a  =  new WrongCat ();


std::cout << "type : " << j->getType() << " " << std::endl;
std::cout << "type : " <<  i->getType() << " " << std::endl;

i->makeSound(); //will output the cat sound!
j->makeSound();//will output the dog sound!
// wrong sound
wr->makeSound ();
a->makeSound ();

delete meta;
delete i;
delete j;
delete wr;
delete a;
//system ("leaks exec");
return 0;
}