#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#pragma once


#include "AMateria.hpp"

class IMateriaSource
{
	protected:
		IMateriaSource();
		IMateriaSource(IMateriaSource const &copy);
		IMateriaSource const &operator=(IMateriaSource const &copy);
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
