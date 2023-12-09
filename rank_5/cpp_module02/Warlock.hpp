#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string	_name;
		std::string _title;
		SpellBook	_SpellBook;
		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		std::string const &getName() const;
		std::string const &getTitle() const;
		void	setTitle(std::string const &title);
		void introduce() const;

		void	learnSpell(ASpell *aspell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, ATarget const &atarget);
};
