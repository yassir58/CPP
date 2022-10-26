#include "ClapTrap.hpp"

int main (void)
{

	ClapTrap defaultClap;
	ClapTrap trapClap ("trapClap");
	ClapTrap anotherClap (trapClap);

	trapClap.attack ("stranger ClapTrap");
	defaultClap.attack ("trapClap");
	defaultClap.beRepaired (1);
	anotherClap.takeDamage (11);
	anotherClap.beRepaired (1);
	return (0);
}