#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <iostream>

class Weapon 
{
	private:
		std::string type;
	public:
		std::string &getType (void);
		void setType (std::string type);
	Weapon (std::string type);
	Weapon (int *type);
	Weapon ();
	~Weapon ();
};

#endif