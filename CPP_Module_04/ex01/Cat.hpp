#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain*	brain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &src);
		~Cat();

		std::string getType(void) const;
		void set_type(std::string type);
		
		void makeSound() const;
};

#endif
