#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
	if (argc < 2)
	{
		std::cout << "Please write ./PmergeMe Value1 Value2 ...\n";
		exit(EXIT_FAILURE);
	}
	PmergeMe			merge(argc, argv);
	return 0;
}
