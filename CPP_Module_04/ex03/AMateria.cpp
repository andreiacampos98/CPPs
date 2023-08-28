#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type=type;
	std::cout << "Constructor AMateria with type" << this->type << "created." << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	set_type(copy.type);
	std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria const &AMateria::operator=(AMateria const &copy)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	this->type = copy.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return(this->type);
}

void	AMateria::set_type(std::string type)
{
	this->type = type;
}