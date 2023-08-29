#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i=0; i<4; i++)
	{
		this->learnInventory[i]=NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy): IMateriaSource(copy), learnInventory()
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy.learnInventory[i])
			this->learnInventory[i] = copy.learnInventory[i];
	}
}
MateriaSource const &MateriaSource::operator=(MateriaSource const &copy)
{
	std::cout << "MateriaSource copy assignment constructor" << std::endl;
	(void) copy;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destroyed" << std::endl;
	for (int i=0; i < 4; i++)
	{
		delete this->learnInventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i=0; i<4; i++)
	{
		if (materia && this->learnInventory[i] == NULL)
		{
			if (this->verifyinInventory(materia)==1)
				this->learnInventory[i] = materia;
			else
				this->learnInventory[i] = materia;
			std::cout << "Materia " << this->learnInventory[i]->getType() << " in the learnMateria" << std::endl;
			return ;
		}
	}
	if(materia)
		std::cout << "Inventory is full " << std::endl;
	else
		std::cout << "Invalid Materia " << std::endl;
	if(verifyinInventory(materia) == 0)
		delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i=0; i<4; i++)
	{
		if(this->learnInventory[i] && this->learnInventory[i]->getType() == type)
			return (this->learnInventory[i]->clone());
	}
	std::cout << "Cannot create materia, " << type << " is invalid!" << std::endl;
	return (0);
}

int MateriaSource::verifyinInventory(AMateria *materia)
{
	for (int i=0; i < 4; i++)
	{
		if(this->learnInventory[i] == materia)
			return 1;
	}
	return 0;
}
