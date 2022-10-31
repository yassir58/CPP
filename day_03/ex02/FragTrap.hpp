#ifndef _FRAG_TRAP
#define _FRAG_TRAP


#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap (void);
		FragTrap (std::string name);
		FragTrap (FragTrap const &other);
		FragTrap &operator= (FragTrap const &other);
		~FragTrap (void);
	public:
		void attack (const std::string &target);
		void highFivesGuys(void);
};



#endif