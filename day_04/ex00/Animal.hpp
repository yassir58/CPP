#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		
		// Destructor
		virtual ~Animal();
		
		// Operators
		Animal & operator=(const Animal &assign);
		// member functions
		virtual void makeSound (void) const;
		virtual std::string getType (void) const;
		
	private:
		
};

#endif