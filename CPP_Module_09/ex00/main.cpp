#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argv;
	if (argc == 2)
	{
		try{
			BitcoinExchange	btc;
			btc.readInput(argv[1]);
		}
		catch(std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	else
	{
		std::cerr << "Please insert ./btc FILE" << std::endl;
		return (1);
	}
	return 0;
}
