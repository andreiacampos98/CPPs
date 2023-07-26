#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	protected:
		std::string _name;
        unsigned int _hit_points;
        unsigned int _energy_points;
        unsigned int _attack_damage;
	public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator = (const ClapTrap &src);
        ~ClapTrap();

		void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
        int getHitPoint(void) const;
        int getEnergyPoints(void) const;
        int getAttackDamage(void) const;
        void setName(const std::string name);
        void setHitPoint(const int value);
        void setEnergyPoints(const int value);
        void setAttackDamage(const int value);
};

#endif
