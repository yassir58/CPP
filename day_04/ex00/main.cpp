#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main (void)
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* wr = new WrongCat ();


std::cout << "type : " << j->getType() << " " << std::endl;
std::cout << "type : " <<  i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
wr->makeSound ();

delete meta;
delete i;
delete j;
delete wr;
return 0;
}