#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main (void)
{
    Animal *animals[10] ;

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
}