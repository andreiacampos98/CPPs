#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	brain = new Brain();
	std::cout << "Constructor Cat default with type " << this->_type << " created." << std::endl;
}

Cat::Cat(std::string type): Animal("Cat")
{
	brain = new Brain();
	this->_type = type;
	std::cout << "Constructor Cat with type " << this->_type << " created." << std::endl;
}

Cat::Cat(const Cat &copy)
{
	this->brain = new Brain(*copy.brain);
	set_type(copy._type);
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->_type = src.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat with type " << this->_type << " destroyed." << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Cat with type " << this->_type << " made a sound: Miau Miau Miau" << std::endl;
}

std::string Cat::getType(void) const
{
	return (this->_type);
}

void Cat::set_type(std::string type)
{
	this->_type=type;
}

Brain 				&Cat::getBrain(void) const
{
	return(*this->brain);
}
