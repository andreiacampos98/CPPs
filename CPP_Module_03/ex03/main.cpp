#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap Ana("Ana");

	Ana.attack("Rui");
	Ana.attack("Manuel");
	Ana.attack("Maria");
	Ana.attack("Leonor");
	Ana.attack("Ana");
	Ana.attack("Jose");
	Ana.highFivesGuys();
	Ana.whoAmI();

    DiamondTrap Filipe("Filipe");

	while (Filipe.getHitPoint())
	{
		Filipe.takeDamage(20);
		Filipe.beRepaired(10);
	}
	Filipe.takeDamage(1);
	Filipe.highFivesGuys();
	Filipe.whoAmI();

    return 0;
}
