#ifndef _CLAP_TRAP_HPP
#define _CLAP_TRAP_HPP

#include <iostream>

class ClapTrap 
{
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
		
	public:
		ClapTrap (void);
		ClapTrap (std::string name);
		ClapTrap (ClapTrap const &other);
		ClapTrap &operator= (ClapTrap const &other);
		~ClapTrap (void);

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif