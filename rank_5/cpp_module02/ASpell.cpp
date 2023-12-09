#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->_effects = effects;
	this->_name = name;
}

ASpell::ASpell(ASpell const &copy)
{
	*this = copy;
}

ASpell &ASpell::operator=(ASpell const &copy)
{
	this->_effects = copy._effects;
	this->_name = copy._name;
	return (*this);
}

std::string	const &ASpell::getName() const
{
	return (this->_name);
}

std::string	const &ASpell::getEffects() const
{
	return (this->_effects);
}

void ASpell::launch(ATarget const &atarget) const
{
	atarget.getHitBySpell(*this);
}
