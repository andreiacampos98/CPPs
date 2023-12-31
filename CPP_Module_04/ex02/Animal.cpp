#include "Animal.hpp"

Animal::Animal(): _type("undefined")
{
	std::cout << "Constructor Animal default with type " << this->_type << " created." << std::endl;
}
Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "Constructor Animal with type " << this->_type << " created." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	set_type(copy._type);
	std::cout << "Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	this->_type = src.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal with type " << this->_type << " destroyed." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal with type " << this->_type << " made a sounnnnnnndddddddd" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::set_type(std::string type)
{
	this->_type=type;
}

