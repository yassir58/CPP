#include "Zombie.hpp"


int main()
{
	Zombie *zombies  = zombieHorde(10, "Zombie tach");

	for (int i = 0; i < 10;i++)
		zombies[i].announce ();

	delete[] zombies;
	while (1);
	return (0);
}