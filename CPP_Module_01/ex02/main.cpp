#include <iostream>

int main()
{
	std::string str;
	std::string *stringPTR;
	std::string &stringREF = str;

	str="HI THIS IS BRAIN";
	stringPTR=&str;
	std::cout << "String inicial: "<< str << std::endl;
	std::cout << "String pointer: " << *stringPTR << std::endl;
	std::cout << "String REF: "<< stringREF << std::endl;
	std::cout << "Address da string "<< &str << std::endl;
	std::cout << "Address da string do Pointer " << stringPTR << std::endl;
	std::cout << "Address da string da REF " << &stringREF << std::endl;
}