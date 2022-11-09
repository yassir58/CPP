#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:

		Brain();
		Brain( Brain const & src );
		Brain (std::string idea);
		~Brain();

		Brain &		operator=( Brain const & rhs );
		std::string getIdea (int indx) const;
		void setIdea (std::string  , int indx) ;

	static  const int count = 100 ;
};

#endif /* *********************************************************** BRAIN_H */