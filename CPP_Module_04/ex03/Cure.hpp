#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#pragma once

#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(Cure const &copy);
	
		Cure const &operator=(Cure const &copy);
		virtual AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
