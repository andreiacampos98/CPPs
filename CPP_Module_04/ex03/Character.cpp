#include "Character.hpp"

Character::Character(void)
{
	this->name="default";
	std::cout << "Character default constructor created." << std::endl;
	for (int i=0; i<4; i++)
	{
		this->inventory[i]=NULL;
	}
}

Character::Character(std::string name)
{
	this->name=name;
	for (int i=0; i<4; i++)
	{
		this->inventory[i]=NULL;
	}
	std::cout << "Character default constructor created with name " << this->name << "." << std::endl;
}

Character::Character(Character const &copy): ICharacter(copy), inventory()
{
	std::cout << "Character copy constructor." << std::endl;
	this->name = copy.name;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i];
	}
}
Character &Character::operator=(Character const &copy)
{
	std::cout << "Character copy assignment." << std::endl;
	this->name = copy.name;
	return(*this);
}

Character::~Character(void)
{
	std::cout << "Character destroyed." << std::endl;
	for (int i=0; i<4; i++)
	{
		delete this->inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (this->name);
}

void	Character::setName(std::string const &name1)
{
	this->name = name1;
}
		
void Character::equip(AMateria* m)
{
	for (int i=0; i<4; i++)
	{
		if (m && this->inventory[i] == NULL)
		{
			if(this->verifyinInventory(m))
				this->inventory[i] = m->clone();
			else
				this->inventory[i] = m;
			std::cout << "Materia with type " << this->inventory[i]->getType() << " equip in the inventory at index " << i << std::endl;
			return ;
		}

	}
	if (m)
		std::cout << "Cannot equip materia, " << this->name << "'s inventory is full!" << std::endl;
	else
		std::cout << "Cannot equip invalid materia" << std::endl;
	if (!this->verifyinInventory(m))
		delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <=3 && this->inventory[idx])
	{
		std::cout << "Unequipped "<< this->inventory[idx]->getType() << " at index " << idx << std::endl;
		this->inventory[idx] = NULL;
	}
	else if (idx > 3 || idx <0)
	{
		std::cout << "Cannot unequip, invalid index" << std::endl;
	}
	else
	{
		std::cout << "Cannot use materia" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <=3 && this->inventory[idx])
	{
		this->inventory[idx]->use(target);
	}
	else if (idx > 3 || idx <0)
	{
		std::cout << "Invalid index " << idx << std::endl;
	}
	else
	{
		std::cout << "Cannot use materia" << std::endl;
	}
}

int Character::verifyinInventory(AMateria *materia)
{
	for (int i=0; i < 4; i++)
	{
		if(this->inventory[i] == materia)
			return 1;
	}
	return 0;
}
