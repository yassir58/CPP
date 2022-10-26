#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

class Cat
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		
	private:
		
};

#endif