#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Warlock.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "ATarget.hpp"
#include <iostream>

int main()
{
	Warlock richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall model1;

	Polymorph* polymorph = new Polymorph();
	TargetGenerator tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);

	Fireball* fireball = new Fireball();

	richard.learnSpell(fireball);

	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);
	delete fireball;
	delete polymorph;
}