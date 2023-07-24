#ifndef WEAPON_HH
#define WEAPON_HH

#include <iostream>

class Weapon{
	private:
		std::string _type;
	public:
		Weapon(std::string str);
		~Weapon(void);
		const std::string& getType(void);
		void setType(std::string str);
};

#endif
