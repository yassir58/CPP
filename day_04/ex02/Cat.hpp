#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal_A.hpp"


class Cat: public Animal_A
{
	private:
		std::string type;
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		void makeSound (void) const ;		
};

#endif