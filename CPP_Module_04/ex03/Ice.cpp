#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

~Ice::Ice(void)
{
	std::cout << "Ice destroyed" << std::endl;
}
		
Ice::Ice(const &copy)
{
	std::cout << "Ice copy constructor" << std::endl;
}
Ice const &Ice::operator=(Ice const &copy)
{
	std::cout << "Ice copy assignment constructor" << std::endl;
	this->type = copy.type;
	return(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "  << target.getName() << " *" << std::endl;
}


AMateria* clone() const
{
	return(new Ice(*this));
}