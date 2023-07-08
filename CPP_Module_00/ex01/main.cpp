#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string value;
	PhoneBook phone;

	std::cout<<"The program only accept ADD, SEARCH and EXIT"<<std::endl;
	while(std::cin >> value)
	{
		if (value == "ADD")
			phone.add();
		else if (value == "SEARCH")
			phone.search();
		else if (value == "EXIT")
		{
			std::cout << "Goodbye!\n";
			return 0;
		}
		else
			std::cout << "oh oh oh wrong input\n";
	}
	return 0;
}