#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieHorde ;

	try
	{
		zombieHorde = new Zombie[N];
	}
	catch(std::bad_alloc&)
	{
		std::cout<<"Allocation failed"<<std::endl;
	}
	for (int i = 0; i < N; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}