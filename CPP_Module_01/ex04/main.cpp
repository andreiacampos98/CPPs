#include "sed.h"

/*The c_str() function in C++ converts a string to an array of characters
and terminates this array with a null character at the end.*/
/*str.find retorna o valor do indice onde encontra a string.
Se o valor do indice corresponder ao valor do indice onde eu estou, eu vou ja substituir se nao vamos avancar*/
int	replace(std::string str, char **argv)
{
	std::ofstream	outfile;
	int pos;

	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if(!outfile.is_open())
		return (1);
	for(int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(argv[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

void read_file(char *str, char **argv)
{
	std::ifstream infile;
	std:: string str1;

	infile.open(str);
	if(!infile.is_open())
	{
		std :: cout << "No such file or directory" <<std::endl;
		return ;
	}
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string file_contents;
	file_contents = buffer.str();
	infile.close();
	replace(file_contents, argv);
}

int	main(int argc, char **argv)
{

	if (argc == 4)
	{
		read_file(argv[1], argv);
	}
	else
	{
		std::cout <<"Wrong inputs." <<std::endl;
		return (1);
	}
	return (0);
}

/*https://www.youtube.com/watch?v=q97E8rOFWSU*/
