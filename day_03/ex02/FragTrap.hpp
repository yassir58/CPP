#ifndef _FRAG_TRAP
#define _FRAG_TRAP


#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		void gaurdGate (void);
	public:
		FragTrap (void);
		FragTrap (std::string name);
		FragTrap (FragTrap const &other);
		FragTrap &operator= (FragTrap const &other);
		~FragTrap (void);
		public:
		void highFivesGuys(void);
};



#endif