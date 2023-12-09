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

Warlock::Warlock(){}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
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
	this->_SpellBook.learnSpell(aspell);
}

void	Warlock::forgetSpell(std::string spellName)
{
	this->_SpellBook.forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget const &atarget)
{
	//if (_SpellBook.createSpell(spellName)) //se existir um spell com este nome
	//	_SpellBook.createSpell(spellName)->launch(atarget);
	ATarget const *test = 0;
    if (test == &atarget)
	{
		std::cout << "launch1\n";
        return;
	}
    ASpell *temp = _SpellBook.createSpell(spellName);
	std::cout << "launch2\n";
    if (temp)
	{
		std::cout << "launch3\n";
        temp->launch(atarget);
	}
}
