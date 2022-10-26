#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main (void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		std::cout << "_________________"  << std::endl;
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack ();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	Weapon test = Weapon (NULL);
	HumanA bob("Bob", test);
	bob.attack();
	test.setType("some other type of club");
	bob.attack();
	return 0;
}