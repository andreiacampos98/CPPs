#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	ClapTrap::_name = "default_clap_name";
	std::cout << "DiamondTrap " << this->_name << " created with default constructor" <<std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap " << this->_name << " created." <<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap " << this->_name << " copied." <<std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &src)
{
	std::cout << "Assignment operator for FragTrap called." <<std::endl;
	FragTrap::operator=(src);
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed." <<std::endl;
}

void DiamondTrap::whoAmI()
{
	if (this->_hit_points <= 0)
		std::cout << "Can't run whoAmI because: DiamondTrap: " << this->_name << " is dead." << std::endl;
	else
	{
		std::cout << "DiamondTrap: " << this->_name << " created." << std::endl;
		std::cout << "Claptrap: " << ClapTrap::_name << " created." << std::endl;
	}
}

/*void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}*/
