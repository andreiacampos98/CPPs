#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

/*int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* k = new Dog("Carnivore");
	const Animal* i = new Cat();
	const WrongAnimal* g = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	g->makeSound();
	h->makeSound();

	delete meta;
	delete j;
	delete k;
	delete i;
	delete g;
	delete h;
	return 0;
}*/

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return 0;
}
