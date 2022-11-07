#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal_A.hpp"


class Dog : public Animal_A
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		virtual ~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
		void makeSound (void) const;
		
		
};

#endif