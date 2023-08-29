#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure default Constructor" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destroyed" <<std::endl;
}

Cure::Cure(Cure const &copy): AMateria(copy)
{
	std::cout << "Cure copy constructor." <<std::endl;
}
	
Cure const &Cure::operator=(Cure const &copy)
{
	std::cout << "Cure copy assignment constructor." <<std::endl;
	this->type = copy.type;
	return(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "  << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return(new Cure(*this));
}
