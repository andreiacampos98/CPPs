#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource const &operator=(MateriaSource const &copy);
		~MateriaSource() {}

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
