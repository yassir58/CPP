#ifndef _FRAG_TRAP
#define _FRAG_TRAP


#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{

	public:
		FragTrap (void);
		FragTrap (std::string name);
		FragTrap (FragTrap const &other);
		FragTrap &operator= (FragTrap const &other);
		virtual ~FragTrap (void);
	public:
		void highFivesGuys(void);
		virtual void attack (const std::string &target);
	static const int hp = 100;
	static const int ad = 30;
};



#endif