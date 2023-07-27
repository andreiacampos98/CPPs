#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap from ClapTrap " << this->_name << " created" <<std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap from ClapTrap " << this->_name << " created." <<std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap from ClapTrap " << this->_name << " copied." <<std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &src)
{
	std::cout << "Assignment operator for FragTrap called." <<std::endl;
	ClapTrap::operator=(src);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap from ClapTrap " << this->_name << " destroyed." <<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hit_points <= 0)
		std::cout << "FragTrap " << this->_name << " is dead." <<std::endl;
	else
		std::cout << "FragTrap " << this->_name << " said high fives" <<std::endl;
}
