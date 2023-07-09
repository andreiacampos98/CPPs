#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
	this->_name = name;
	std::cout << "HumanB named " << name << " created with no weapon." << std::endl;
}
HumanB::~HumanB(void)
{
	std::cout << "HumanB destroyed " << this->_name << std::endl;
}
void HumanB::attack(void)
{
	std::cout<<this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}