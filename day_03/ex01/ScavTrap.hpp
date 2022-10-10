#ifndef _SCAV_TRAP
#define _SCAV_TRAP


#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		void gaurdGate (void);
	public:
		ScavTrap (void);
		ScavTrap (std::string name);
		ScavTrap (ScavTrap const &other);
		ScavTrap &operator= (ScavTrap const &other);
		~ScavTrap (void);
};



#endif