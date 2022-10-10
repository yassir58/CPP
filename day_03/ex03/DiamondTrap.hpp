#ifndef _DIAMOND_TRAP
#define _DIAMOND_TRAP


#include "ScavTrap.hpp"
#include "FragTrap.hpp"



class DiamondTrap: public ScavTrap, public fragTrap 
{
	private:
		std::string name;
	public:
		DiamondTrap (void);
		DiamondTrap (std::string name);
		DiamondTrap (DiamondTrap const &other);
		DiamondTrap &operator=  (DiamondTrap const &other);
		~DiamondTrap (void); 
};



#endif