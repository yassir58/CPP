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
	(void)name;
	for (int i = 0; i < N; i++)
	{
		std::cout<<&zombieHorde[i]<<' ' <<zombieHorde <<std::endl;
		zombieHorde[i].setName(std::to_string(i));
	}
	return (zombieHorde);
}