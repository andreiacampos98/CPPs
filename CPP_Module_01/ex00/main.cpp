#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	*z = newZombie("Andreia");
	z->announce();
	randomChump("Bruno");
	delete z;
}