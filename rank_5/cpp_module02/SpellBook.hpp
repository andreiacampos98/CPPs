#pragma once
#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		std::map < std::string , ASpell * > _SpellBook;
		SpellBook(SpellBook const &copy);
		SpellBook &operator=(SpellBook const &copy);
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *aspell);
		void	forgetSpell(std::string const &spellName);
		ASpell *createSpell(std::string const &name);
};
