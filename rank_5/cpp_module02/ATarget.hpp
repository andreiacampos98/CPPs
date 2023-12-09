#pragma once
#include <iostream>


class ASpell;

class ATarget{
	private:
		std::string type;
	public:
		ATarget(std::string type);
		virtual ~ATarget();
		ATarget(ATarget const &copy);
		ATarget &operator=(ATarget const &copy);
		virtual ATarget *clone() const = 0;
		std::string getType() const;

		void getHitBySpell(ASpell const &aspell) const;
};

//std::ostream& operator<<(std::ostream& os, ATarget const& src);

#include "ASpell.hpp"
