#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator = (const DiamondTrap &src);
        ~DiamondTrap();

		void whoAmI();
		void attack(std::string const &target);
};

#endif

/***********************Makefile Flags*****************************

-Wshadow warns whenever a local variable or type declaration shadows 
another variable, parameter, class member, etc.

-pedantic issues all warnings demanded by strict ISO C++ rules 
if you want to be extra safe

******************************************************************/
