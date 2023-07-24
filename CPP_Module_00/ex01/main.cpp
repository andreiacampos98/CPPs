#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string value;
	PhoneBook phone;

	std::cout<<"The program only accept the following commands: ADD, SEARCH and EXIT"<<std::endl;
	while (value != "EXIT")
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, value);
		if (value == "ADD")
			phone.add();
		else if (value == "SEARCH")
			phone.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}