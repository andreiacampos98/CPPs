#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor created." << std::endl;
}

Character::Character(std::string name)
{
	this->name=name;
	std::cout << "Character default constructor created with name " << this->name << "." << std::endl;
}

Character::Character(Character const &copy)
{
	std::cout << "Character copy constructor." << std::endl;
	*this=copy;
}
Character &Character::operator=(Character const &copy)
{
	std::cout << "Character copy assignment." << std::endl;
	this->name=copy.name;
	return(*this);
}

Character::~Character(void)
{
	std::cout << "Character destroyed." << std::endl;
}

std::string const & Character::getName() const
{
	return (this->name);
}
		
void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx);

void Character::use(int idx, Character& target);
