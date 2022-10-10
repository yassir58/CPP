#include "ClapTrap.hpp"
#include "fragTrap.hpp"



int main (void)
{

	fragTrap Scv("farg");

	Scv.attack ("ScavTrap");
	Scv.takeDamage (15);
	Scv.ClapTrap::takeDamage (120);
	Scv.beRepaired (15);
	Scv.highFivesGuys ();
	return (0);
}