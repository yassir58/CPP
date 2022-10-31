#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"



int main (void)
{
	DiamondTrap Scv("jhon doe");
	DiamondTrap *Frd = new DiamondTrap ("mark");

	Scv.attack ("andrew tate");
	Scv.takeDamage (15);
	Scv.ClapTrap::takeDamage (10);
	Scv.beRepaired (15);
	Scv.gaurdGate ();
	Scv.highFivesGuys ();
	Scv.whoAmI ();
	Scv.attack ("random Scav");
	Frd->whoAmI ();

	delete Frd;
	return (0);
}