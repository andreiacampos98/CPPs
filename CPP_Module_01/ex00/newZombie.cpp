#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}

/*Operator new is a function that allocates raw memory and conceptually a bit similar 
to malloc().

    It is the mechanism of overriding the default heap allocation logic.
    It doesn’t initializes the memory i.e constructor is not called. However, 
	after our overloaded new returns, the compiler then automatically calls the constructor 
	also as applicable.
    It’s also possible to overload operator new either globally, or for a specific class*/
