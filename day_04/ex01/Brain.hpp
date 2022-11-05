#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string idea;
		std::string ideas[100];
	public:

		Brain();
		Brain (std::string idea);
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );
		std::string getIdea (int indx) const;

	static  const int count = 100 ;
};

#endif /* *********************************************************** BRAIN_H */