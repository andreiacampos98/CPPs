# include "Harl.hpp"

int convert(char *argv)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i=0; i < 4; i++)
	{
		if (levels[i] == argv)
			return (i);
	}
	return (-1);
}

void	execute_functions(char *argv, Harl &H1)
{
	switch(convert(argv))
	{
		case 0:
			H1.complain("DEBUG");
		case 1:
			H1.complain("INFO");
		case 2:
			H1.complain("WARNING");
		case 3:
			H1.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}



int main(int argc, char **argv)
{
	Harl H1;

	if(argc != 2)
		std::cout << "Arguments are not correct." << std::endl;
	else
		execute_functions(argv[1], H1);
	return(0);
}
