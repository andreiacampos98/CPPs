#pragma once

#include <iostream>

class ATarget;

class ASpell{
	private:
		std::string _name;
		std::string _effects;
	public:
		ASpell();
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();
		ASpell(ASpell const &copy);
		ASpell &operator=(ASpell const &copy);
		std::string	const &getName() const;
		std::string	const &getEffects() const;
		void launch(ATarget const &atarget) const;
		virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"