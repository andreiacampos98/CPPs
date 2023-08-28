#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		
		Ice(const &copy);
		Ice const &operator=(Ice const &copy);
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
