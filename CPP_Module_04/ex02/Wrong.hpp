#ifndef WRONG_HPP
#define WRONG_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &src);
		virtual ~WrongAnimal();

		virtual void makeSound() const;

		std::string getType(void) const;
		void set_type(std::string type);
};

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &src);
		~WrongCat();

		std::string getType(void) const;
		void set_type(std::string type);
		
		void makeSound() const;
};

#endif
