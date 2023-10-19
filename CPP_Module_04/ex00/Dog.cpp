#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Constructor Dog default with type " << this->_type << " created." << std::endl;
}

Dog::Dog(std::string type): Animal("Dog")
{
	this->_type = type;
	std::cout << "Constructor Dog with type " << this->_type << " created." << std::endl;
}

Dog::Dog(const Dog &copy)
{
	set_type(copy._type);
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog with type " << this->_type << " destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog with type " << this->_type << " made a sound: Au Au Au Au" << std::endl;
}

std::string Dog::getType(void) const
{
	return (this->_type);
}

void Dog::set_type(std::string type)
{
	this->_type=type;
}
