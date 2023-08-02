#include "Wrong.hpp"

WrongAnimal::WrongAnimal(): _type("undefined")
{
	std::cout << "Constructor Wrong Animal with type " << this->_type << " default created." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << "Constructor Wrong Animal with type " << this->_type << " created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	set_type(copy._type);
	std::cout << "Copy Wrong Animal constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Wrong Animal Copy assignment operator called" << std::endl;
	this->_type = src.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal with type " << this->_type << " destroyed." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal with type " << this->_type << " made a sound." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::set_type(std::string type)
{
	this->_type = type;
}

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "Constructor WrongCat default with type " << this->_type << " created." << std::endl;
}
WrongCat::WrongCat(std::string type): WrongAnimal("WrongCat")
{
	this->_type = type;
	std::cout << "Constructor WrongCat with type " << this->_type << " created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	set_type(copy._type);
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	this->_type = src.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat with type " << this->_type << " destroyed." << std::endl;
}


std::string WrongCat::getType(void) const
{
	return (this->_type);
}

void WrongCat::set_type(std::string type)
{
	this->_type = type;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat with type " << this->_type << " made a sound: mi mi mi" << std::endl;
}
