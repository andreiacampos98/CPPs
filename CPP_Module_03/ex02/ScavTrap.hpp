#ifndef SCAVTRAP_HH
#define SCAVTRAP_HH

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator = (const ScavTrap &src);
        ~ScavTrap();

		void guardGate();
};

#endif
