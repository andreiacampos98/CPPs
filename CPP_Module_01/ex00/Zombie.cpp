#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie" << this->name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout<<"Goodbye " << this->name <<std::endl;
}

void Zombie::announce(void)
{
	std::cout<<this->name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}