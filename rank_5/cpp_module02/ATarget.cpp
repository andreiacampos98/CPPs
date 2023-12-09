#include "ATarget.hpp"

ATarget::~ATarget() {}

ATarget::ATarget(std::string type)
{
	this->type = type;
}

ATarget::ATarget(ATarget const &copy)
{
	*this = copy;
}

ATarget &ATarget::operator=(ATarget const &copy)
{
	this->type = copy.type;
	return (*this);
}

std::string ATarget::getType() const
{
	return (this->type);
}

void ATarget::getHitBySpell(ASpell const &aspell) const
{
	std::cout << type << " has been " << aspell.getEffects() << "!" << std::endl;
}

/*std::ostream& operator<<(std::ostream& os, ATarget const& src)
{
	os << src.getType();
	return(os);
}*/