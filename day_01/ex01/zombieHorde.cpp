#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

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
		zombieHorde[i] = *(newZombie (name));
	return (zombieHorde);
}