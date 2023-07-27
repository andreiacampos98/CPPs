#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap Andreia("Andreia");

	Andreia.attack("Rui");
	Andreia.attack("Manuel");
	Andreia.attack("Maria");
	Andreia.attack("Leonor");
	Andreia.attack("Ana");
	Andreia.attack("Jose");
	Andreia.guardGate();

    ScavTrap Rui("Rui");

	while (Rui.getHitPoint())
	{
		Rui.takeDamage(20);
		Rui.beRepaired(10);
	}
	Rui.takeDamage(1);
	Rui.guardGate();

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
