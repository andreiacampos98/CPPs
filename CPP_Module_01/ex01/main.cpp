#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie *z;
	z=zombieHorde(10, "Andreia");
	for (int i = 0; i < 10; i++)
		z[i].announce();
	delete [] z;
}