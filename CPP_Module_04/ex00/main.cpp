#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* k = new Dog("Carnivore");
	const Animal* i = new Cat();
	const WrongAnimal* g = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();
	const WrongCat* l = new WrongCat("WrongCat");
	std::cout<< "............................................" <<std::endl;
	std::cout << "Animal type: " << j->getType() << std::endl;
	std::cout << "Animal type: " << i->getType() << std::endl;
	std::cout << "Animal type: " << h->getType() << std::endl;
	std::cout<< "............................................" <<std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();
	g->makeSound();
	h->makeSound();
	l->makeSound();
	std::cout<< "............................................" <<std::endl;
	delete meta;
	delete j;
	delete k;
	delete i;
	delete g;
	delete h;
	delete l;
	return 0;
}
