#ifndef _ZOMBIE_HPP
#define _ZOMBIE_HPP


#include <iostream>
#include <cctype>
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		void announce( void );
		void setName (std::string name);

		Zombie(std::string name);
		Zombie();
		~Zombie();
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );
#endif