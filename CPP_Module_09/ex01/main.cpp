#include "RPN.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		try{
			parser(argv[1]);
		}catch(std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	if (argc != 2)
		std::cout << "Incorrect arguments\n" << std::endl;
	return 0;
}
