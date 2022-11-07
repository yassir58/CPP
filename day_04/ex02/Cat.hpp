#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal_A.hpp"


class Cat: public Animal_A
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		virtual ~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		void makeSound (void) const ;		
};

#endif