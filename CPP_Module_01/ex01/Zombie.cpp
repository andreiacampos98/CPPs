#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie" << this->_name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout<<"Goodbye " << this->_name <<std::endl;
}

void Zombie::announce(void)
{
	std::cout<<this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}