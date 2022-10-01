#include "Zombie.hpp"



int main (void)
{
	Zombie *test;

	test = newZombie ("alex");
	test->announce();
	randomChump("jeffrey");
	delete test;
	return (0);
}