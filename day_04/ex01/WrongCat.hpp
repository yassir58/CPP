#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"
# include "Brain.hpp"


class WrongCat: public WrongAnimal
{
	private:
		std::string type;
		Brain *brain;
	public:
		// Constructors
		WrongCat();
		
		// Destructor
		~WrongCat();
		
		// Operators
		WrongCat & operator=(const WrongCat &assign);
		void makeSound (void) const ;
		
};

#endif