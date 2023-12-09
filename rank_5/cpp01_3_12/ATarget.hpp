#pragma once
#include <iostream>

class ASpell;

class ATarget{
	private:
		std::string _type;
	public:
		ATarget();
		ATarget(std::string const &type);
		virtual ~ATarget();
		ATarget(ATarget const &copy);
		ATarget &operator=(ATarget const &copy);
		virtual ATarget *clone() const = 0;
		std::string const &getType() const;

		void getHitBySpell(ASpell const &aspell) const;
};

#include "ASpell.hpp"