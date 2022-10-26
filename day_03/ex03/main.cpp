#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"



int main (void)
{
	DiamondTrap Scv("7mida");
	DiamondTrap *Frd = new DiamondTrap ("Freda");

	Scv.attack ("sa9azo");
	Scv.takeDamage (15);
	Scv.ClapTrap::takeDamage (10);
	Scv.beRepaired (15);
	Scv.gaurdGate ();
	Scv.highFivesGuys ();
	Scv.whoAmI ();
	Scv.attack ("srghini");
	Frd->whoAmI ();

	delete Frd;
	return (0);
}