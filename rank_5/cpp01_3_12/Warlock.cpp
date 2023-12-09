#include "Warlock.hpp"

Warlock::Warlock(Warlock const &copy)
{
	*this = copy;
}

Warlock &Warlock::operator=(Warlock const &copy)
{
	this->_name = copy._name;
	this->_title = copy._title;
	return(*this);
}

/*tem de ter const e as variaveis tem de ser referencias.*/
Warlock::Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
	{
		delete it->second;
	}
	_SpellBook.clear();
}

std::string const &Warlock::getName() const
{
	return (this->_name);
}

std::string const &Warlock::getTitle() const
{
	return (this->_title);
}

void	Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *aspell)
{
	if (aspell)
		if (_SpellBook.find(aspell->getName()) == _SpellBook.end()) //se nao existir um spell com este nome
			_SpellBook[aspell->getName()] = aspell->clone();
}

void	Warlock::forgetSpell(std::string spellName)
{
	if (_SpellBook.find(spellName) != _SpellBook.end()) //se existir um spell com este nome
		_SpellBook.erase(_SpellBook.find(spellName)); //elimina(erase) no spellBook
}

void	Warlock::launchSpell(std::string spellName, ATarget const &atarget)
{
	if (_SpellBook.find(spellName) != _SpellBook.end()) //se existir um spell com este nome
		_SpellBook[spellName]->launch(atarget);
}
