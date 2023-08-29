#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#pragma once
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character(void);
		Character (std::string name);
		Character(Character const &copy);
		Character &operator=(Character const &copy);
		~Character(void);
		
		std::string const & getName() const;
		void	setName(std::string const &name1);
		
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		int verifyinInventory(AMateria *materia);
};

#endif
