#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal_A.hpp"


class Dog : public Animal_A
{
	private:
		std::string type;
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
		void makeSound (void) const;
		
		
};

#endif