#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#pragma once

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*learnInventory[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource const &operator=(MateriaSource const &copy);
		~MateriaSource();

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
		int verifyinInventory(AMateria *materia);
};

#endif
