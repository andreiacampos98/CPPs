#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout <<"HumanA named " << name << " created with weapon ";
	std::cout << weapon.getType() << std::endl;
}
HumanA::~HumanA(void)
{
	std::cout << "HumanA destroyed " << this->_name << std::endl;
}
void HumanA::attack(void)
{
	std::cout<<this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}