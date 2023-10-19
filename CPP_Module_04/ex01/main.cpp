#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main()
{
	const Animal* j[5];
	const Animal* i[5];

	for (int a=0; a < 5; a++)
		j[a] = new Dog();
	for (int a=0; a < 5; a++)
		i[a] = new Cat();
	std::cout<< "............................................" <<std::endl;
	Brain *brain;
	brain = &j[0]->getBrain();
	brain->set_idea("You are awesome!", 1);
	brain->set_idea("Keep going", 2);
	std::cout << "Print the ideas" <<std::endl;
	std::cout << j[0]->getBrain().get_idea(1) <<std::endl;
	std::cout << j[0]->getBrain().get_idea(2) <<std::endl;
	std::cout<< "............................................" <<std::endl;
	for (int a=0; a < 5; a++)
		delete j[a];
	for (int a=0; a < 5; a++)
		delete i[a];
		
	Dog dog1;
	Dog dog2(dog1);

	dog1.getBrain().set_idea("Dog1\n", 1);
	std::cout << dog1.getBrain().get_idea(1) <<std::endl;
	std::cout << dog2.getBrain().get_idea(1) <<std::endl;
	std::cout << "\n";

	std::cout << "\n\n";

	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	cat1.getBrain().set_idea("cat1\n", 1);
	std::cout << cat1.getBrain().get_idea(1) <<std::endl;
	std::cout << cat2.getBrain().get_idea(1) <<std::endl;
	std::cout << "\n";

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
