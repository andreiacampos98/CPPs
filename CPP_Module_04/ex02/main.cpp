#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main()
{
	const Animal* j[5];
	const Animal* i[5];


	//teste = new Animal();
	for (int a=0; a < 4; a++)
		j[a] = new Dog();
	for (int a=0; a < 4; a++)
		i[a] = new Cat();
	std::cout<< "............................................" <<std::endl;
	Brain *brain;
	brain = &j[0]->getBrain();
	brain->set_idea("Andreia linda", 1);
	brain->set_idea("ola", 2);
	std::cout << "Print the ideas" <<std::endl;
	for (int k=0; k<100; k++)
		std::cout << "Print idea index "<< k << j[0]->getBrain().get_idea(k) << "." <<std::endl;
	//std::cout << j[0]->getBrain().get_idea(2) <<std::endl;
	std::cout<< "............................................" <<std::endl;
	for (int a=0; a < 4; a++)
		delete j[a];
	for (int a=0; a < 4; a++)
		delete i[a];
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		catA->getBrain().set_idea("Sim", 1);
		catA->getBrain().set_idea("Nao", 2);
		std::cout << "Print the ideas" <<std::endl;
		for (int k=0; k<100; k++)
			std::cout << "Print idea index "<< k << catA->getBrain().get_idea(k) << "." <<std::endl;
		for (int k=0; k<100; k++)
			std::cout << "Print idea index "<< k << catB->getBrain().get_idea(k) << "." <<std::endl;
		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		catA->getBrain().set_idea("Andreia linda", 1);
		catA->getBrain().set_idea("ola", 2);
		std::cout << "Print the ideas" <<std::endl;
		for (int k=0; k<100; k++)
			std::cout << "Print idea index "<< k << catA->getBrain().get_idea(k) << "." <<std::endl;
		for (int k=0; k<100; k++)
			std::cout << "Print idea index "<< k << catB->getBrain().get_idea(k) << "." <<std::endl;
		delete catA;
		delete catB;
	}
	std::cout << "\nola\n" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
	Cat basic1;
	{
		Cat tmp1 = basic1;
	}
	return 0;
	//Animal Animal;
}
