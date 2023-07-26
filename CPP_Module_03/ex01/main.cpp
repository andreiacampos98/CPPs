#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    return 0;
}
