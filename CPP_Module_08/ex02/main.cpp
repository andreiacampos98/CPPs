#include "MutantStack.hpp"

/*
    The std::stack class is a container adapter that gives the programmer 
    the functionality of a stack (a LIFO (last-in, first-out) data structure).

    The class template acts as a wrapper to the underlying container - 
    only a specific set of functions is provided. 
    The stack pushes and pops the element from the back of the underlying container, known as the top of the stack

    stacks are implemented as container adaptors, which are classes that use an encapsulated object 
    of a specific container class as its underlying container, providing a specific set of member 
    functions to access its elements

    The following operations are supported:
        empty: check if the stack is empty or not
        size: returns the number of elements present in the stack
        push: insert the element at the top of the stack
        pop: removes single topmost element from the stack. It does not return anything
        top: returns the topmost element of the stack. It returns the element but not removes it.
        swap: swaps the elements of the two stacks
*/

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
  	std::cout << "\n---Iterator---" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n--- Reverse iterator ---" << std::endl;

	MutantStack<std::string> rev;

	rev.push("one");
	rev.push("two");
	rev.push("three");
	rev.push("four");
	rev.push("five");

	MutantStack<std::string>::reverse_iterator rev_itr = rev.rbegin();
	for (; rev_itr != rev.rend(); rev_itr++)
		std::cout << *rev_itr << std::endl;

	std::cout << "\n--- Copy constructor ---" << std::endl;

	MutantStack<int> copy(mstack);

	copy.pop();
	copy.pop();
	copy.pop();
	copy.push(64);
	copy.push(65);
	copy.push(66);

	MutantStack<int>::iterator copy_itr = copy.begin();
	for (; copy_itr != copy.end(); copy_itr++)
		std::cout << *copy_itr << std::endl;

	std::cout << "\n--- Assignment operator ---" << std::endl;
	MutantStack<int> a_copy;
	a_copy = mstack;

	a_copy.pop();
	a_copy.pop();
	a_copy.pop();
	a_copy.push(128);
	a_copy.push(129);
	a_copy.push(130);

	MutantStack<int>::iterator a_copy_itr = a_copy.begin();
	for (; a_copy_itr != a_copy.end(); a_copy_itr++)
		std::cout << *a_copy_itr << std::endl;

	std::cout << "\nNow with list!!!" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Top: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lst_it = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();
	++it;
	--it;
	while (lst_it != lst_ite)
	{
		std::cout << *lst_it << std::endl;
		++lst_it;
  	}
	std::list<int> l(lst);
	return 0;
}
