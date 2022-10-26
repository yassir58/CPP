#ifndef _HUMAN_B_HPP_
#define _HUMAN_B_HPP_

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		void attack(void);
		void setWeapon (Weapon &weapon);
	HumanB (std::string name);
	HumanB ();
	~HumanB();
};

#endif