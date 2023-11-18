#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argv;
	if (argc == 2)
	{
		BitcoinExchange	btc;

		
	}
	else
	{
		std::cerr << "Please insert ./btc FILE" << std::endl;
		return (1);
	}
	return 0;
}
