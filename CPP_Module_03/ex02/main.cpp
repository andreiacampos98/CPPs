#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap Ana("Ana");

	Ana.attack("Rui");
	Ana.attack("Manuel");
	Ana.attack("Maria");
	Ana.attack("Leonor");
	Ana.attack("Ana");
	Ana.attack("Jose");
	Ana.highFivesGuys();

    FragTrap Filipe("Filipe");

	while (Filipe.getHitPoint())
	{
		Filipe.takeDamage(20);
		Filipe.beRepaired(10);
	}
	Filipe.takeDamage(1);
	Filipe.highFivesGuys();

    return 0;
}
