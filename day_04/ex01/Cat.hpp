#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include  "Brain.hpp"

class Cat: public Animal
{
	private:
		std::string type;
		Brain *brain;
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		void makeSound (void) const ;
		std::string getType (void) const;
};

#endif