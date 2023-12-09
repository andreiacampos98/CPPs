#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::~ATarget() {}

ATarget::ATarget(std::string const &type)
{
	this->_type = type;
}

ATarget::ATarget(ATarget const &copy)
{
	*this = copy;
}

ATarget &ATarget::operator=(ATarget const &copy)
{
	this->_type = copy._type;
	return (*this);
}

std::string const &ATarget::getType() const
{
	return (this->_type);
}

void ATarget::getHitBySpell(ASpell const &aspell) const
{
	std::cout << _type << " has been " << aspell.getEffects() << "!" << std::endl;
}
