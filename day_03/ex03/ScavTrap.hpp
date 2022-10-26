#ifndef _SCAV_TRAP
#define _SCAV_TRAP


#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap (void);
		ScavTrap (std::string name);
		ScavTrap (ScavTrap const &other);
		ScavTrap &operator= (ScavTrap const &other);
		virtual ~ScavTrap (void);
	public:
		void attack (const std::string &target);
		void gaurdGate (void);
	static const int ep = 50;
};
#endif