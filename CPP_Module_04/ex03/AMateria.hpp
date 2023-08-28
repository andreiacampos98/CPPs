#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;

		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
	public:
		virtual ~AMateria(void);

		AMateria const &operator=(AMateria const &copy);

		std::string const & getType() const; //Returns the materia type
		void	set_type(std::string type);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
