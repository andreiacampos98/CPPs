#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#pragma once

#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &copy);
		~Ice(void);
		
		Ice const &operator=(Ice const &copy);
		virtual AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
