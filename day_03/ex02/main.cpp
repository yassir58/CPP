#include "ClapTrap.hpp"
#include "FragTrap.hpp"



int main (void)
{

	FragTrap Scv("farg");

	Scv.attack ("ScavTrap");
	Scv.takeDamage (15);
	Scv.ClapTrap::takeDamage (120);
	Scv.beRepaired (15);
	Scv.highFivesGuys ();
	return (0);
}