#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const &copy)
{
	*this = copy;
}

SpellBook &SpellBook::operator=(SpellBook const &copy)
{
	this->_SpellBook = copy._SpellBook;
	return(*this);
}

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
	{
		delete it->second;
	}
	_SpellBook.clear();
}

void	SpellBook::learnSpell(ASpell *aspell)
{
	if (aspell)
		if (_SpellBook.find(aspell->getName()) == _SpellBook.end()) //se nao existir um spell com este nome
			_SpellBook[aspell->getName()] = aspell->clone();
}

void	SpellBook::forgetSpell(std::string const &spellName)
{
	if (_SpellBook.find(spellName) != _SpellBook.end()) //se existir um spell com este nome
	{
		delete _SpellBook.find(spellName)->second;
		_SpellBook.erase(_SpellBook.find(spellName)); //elimina(erase) no spellBook
	}
}

ASpell	*SpellBook::createSpell(std::string const &name)
{
	ASpell*	tmp = NULL;
	if (_SpellBook.find(name) != _SpellBook.end()) //se existir um spell com este nome
		tmp = _SpellBook[name];
	return (tmp);
}
