#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
	public:
		Animal &operator=(const Animal &src);
		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType(void) const;
		void set_type(std::string type);
		virtual Brain 		&getBrain(void) const = 0;
};


#endif
