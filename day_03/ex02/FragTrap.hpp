#ifndef _FRAG_TRAP
#define _FRAG_TRAP


#include "ClapTrap.hpp"

class fragTrap: public ClapTrap
{
	public:
		void gaurdGate (void);
	public:
		fragTrap (void);
		fragTrap (std::string name);
		fragTrap (fragTrap const &other);
		fragTrap &operator= (fragTrap const &other);
		~fragTrap (void);
		public:
		void highFivesGuys(void);
};



#endif