#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "ICharacter default constructor" << std::endl;
}

ICharacter::ICharacter(ICharacter const &copy)
{
	std::cout << "ICharacter copy constructor" << std::endl;
	*this = copy;
}
ICharacter const &ICharacter::operator=(ICharacter const &copy)
{
	std::cout << "ICharacter copy assignment constructor" << std::endl;
	(void) copy;
	return (*this);
}