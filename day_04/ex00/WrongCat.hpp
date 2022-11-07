#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(const WrongCat &copy);
		
		// Destructor
		~WrongCat();
		
		// Operators
		WrongCat & operator=(const WrongCat &assign);
		void makeSound (void) const ;
		
};

#endif