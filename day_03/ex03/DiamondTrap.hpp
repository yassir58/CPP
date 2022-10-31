#ifndef _DIAMOND_TRAP
#define _DIAMOND_TRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap (void);
		DiamondTrap (std::string name);
		DiamondTrap (DiamondTrap const &other);
		DiamondTrap &operator=  (DiamondTrap const &other);
		virtual ~DiamondTrap (void); 
	public:
		using ScavTrap::attack;
		void whoAmI(void) const;
};

#endif