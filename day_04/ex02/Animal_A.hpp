#ifndef ANIMAL_A_HPP
# define ANIMAL_A_HPP

# include <iostream>
# include <string>

class Animal_A
{
	protected:
		std::string type;
	public:
		// Constructors
		Animal_A();
		Animal_A(const Animal_A &copy);
		
		// Destructor
		virtual ~Animal_A();
		
		// Operators
		Animal_A & operator=(const Animal_A &assign);
		// member functions

		// pure virtual function
		virtual void makeSound (void) const = 0;
		std::string getType (void) const;
	private:
		
};

#endif