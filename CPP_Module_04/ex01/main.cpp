#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main()
{
	const Animal* j[5];
	const Animal* i[5];

	for (int a=0; a < 4; a++)
		j[a] = new Dog();
	for (int a=0; a < 4; a++)
		i[a] = new Cat();
	std::cout<< "............................................" <<std::endl;
	Brain *brain;
	brain = &j[0]->getBrain();
	brain->set_idea("You are awesome!", 1);
	brain->set_idea("Hello", 2);
	std::cout << "Print the ideas" <<std::endl;
	std::cout << j[0]->getBrain().get_idea(1) <<std::endl;
	std::cout << j[0]->getBrain().get_idea(2) <<std::endl;
	std::cout<< "............................................" <<std::endl;
	for (int a=0; a < 4; a++)
		delete j[a];
	for (int a=0; a < 4; a++)
		delete i[a];

	std::cout << "-------------------------------------\n\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		std::cout << "     ---------------------     \n";
		Dog *dogB = new Dog(*dogA);
		std::cout << "     ---------------------     \n";
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		std::cout << "     ---------------------     \n";
		*dogA = *dogB;
		std::cout << "     ---------------------     \n";
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		std::cout << "     ---------------------     \n";
		Cat *catB = new Cat(*catA);
		std::cout << "     ---------------------     \n";
		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;
		std::cout << "     ---------------------     \n";
		*catA = *catB;
		std::cout << "     ---------------------     \n";
		delete catA;
		delete catB;
	}
	return 0;
}
