#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(Cure const &copy);
	
		Cure const &operator=(Cure const &copy);
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
