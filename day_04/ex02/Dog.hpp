#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

class Dog
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
		
	private:
		
};

#endif