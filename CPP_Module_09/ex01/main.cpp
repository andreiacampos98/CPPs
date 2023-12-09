#include "RPN.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		parser(argv[1]);
	}
	if (argc != 2)
		std::cout << "Incorrect arguments\n" << std::endl;
	return 0;
}
