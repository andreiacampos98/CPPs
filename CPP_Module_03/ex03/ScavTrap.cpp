#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap from ClapTrap " << this->_name << " created" <<std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap from ClapTrap " << this->_name << " created." <<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    std::cout << "ScavTrap from ClapTrap " << this->_name << " copied." <<std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &src)
{
    std::cout << "Assignment operator for ScavTrap called." <<std::endl;
    ClapTrap::operator=(src);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap from ClapTrap " << this->_name << " destroyed." <<std::endl;
}

void ScavTrap::guardGate()
{
    if (this->_hit_points <= 0)
        std::cout << "Cannot switch to Gate keeper mode." <<std::endl;
    else
        std::cout << "ScavTrap is now in Gate keeper mode." <<std::endl;
}


