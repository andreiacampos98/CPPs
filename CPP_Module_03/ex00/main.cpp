#include "ClapTrap.hpp"

int main()
{
    /*std::string name;
    std::string target;

    name = "Andreia";
    target = "Rui";
	ClapTrap    A(name);
    ClapTrap    B(target);
    A.attack(target);*/
    //B.takeDamage(100);
    //B.beRepaired(100);
    ClapTrap clap("Frank");
	ClapTrap clap2;

	clap.takeDamage(5);
	clap.takeDamage(4);

	clap2.attack("John");
	clap2.takeDamage(20);

	clap2 = clap;
	clap2.setName("Gonk");

	clap.beRepaired(8);
	clap.beRepaired(8);
	clap.beRepaired(8);
	clap.beRepaired(8);
	clap.beRepaired(8);
	clap.beRepaired(8);
	clap.beRepaired(8);
	clap.beRepaired(8);
	clap.beRepaired(8);

	clap.beRepaired(8);
	clap.attack("Gonk");



	clap.takeDamage(6);
	clap.takeDamage(6);

	clap2.takeDamage(6);
	clap2.takeDamage(6);
    return 0;
}
