#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Frank"); //constructor
	ClapTrap clap2; //default constructor

	clap.takeDamage(5);
	clap.takeDamage(4);

	clap2.attack("John");
	clap2.takeDamage(20);

	clap2 = clap; //copy assigment operator
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
