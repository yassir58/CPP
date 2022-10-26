#ifndef _HUMAN_A_HPP_
#define _HUMAN_A_HPP_

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		void attack(void);
	HumanA (std::string name, Weapon &weapon);
	// HumanA ();
	~HumanA ();
};

#endif