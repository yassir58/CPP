#include "ClapTrap.hpp"
#include "ScavTrap.hpp"



int main (void)
{

	ScavTrap Scv("SCV");

	Scv.attack ("ClapTrap");
	Scv.takeDamage (15);
	Scv.ClapTrap::takeDamage (10);
	Scv.beRepaired (15);
	Scv.gaurdGate ();
	return (0);
}