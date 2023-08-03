#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain*	brain;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &src);
		~Dog();

		std::string 	getType(void) const;
		void 			set_type(std::string type);
		Brain 			&getBrain(void) const;
		
		void makeSound() const;

};

#endif
