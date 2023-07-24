#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	std::cout<< "Let's create a PhoneBook up to 8 contacts!!" << std::endl;
}
PhoneBook::~PhoneBook(void)
{
	std::cout<< "See you soon" <<std::endl;
}

void	PhoneBook::add(void)
{
	std::string str;

	str = "";
	if (this->_index > 7)
		std::cout <<"We are replacing a contact " \
			<< this->_Contacts[this->_index % 8].get_first_name() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_Contacts[this->_index % 8].set_first_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_Contacts[this->_index % 8].set_last_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_Contacts[this->_index % 8].set_nickname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a phonenumber: ";
		if (std::getline(std::cin, str) && str != "")
			this->_Contacts[this->_index % 8].set_phone_number(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_Contacts[this->_index % 8].set_darkest_secret(str);
			std::cout << this->_Contacts[this->_index % 8].get_first_name() << \
				" successfully added to phonebook [" << this->_index % 8 + 1 << "/8]" << std::endl;
		}
	}
	this->_index++;
}

std::string add_spaces(int n)
{
	std::string str;

	while(n--)
		str.append(" ");
	return(str);
}

std::string fix_width(std::string str, long unsigned max_len)
{
	if (str.size() > max_len)
	{
		str.resize(max_len);
		str[str.size() - 1] = '.';
	}
	return(str);
}

int	print_list(Contact Contact[8])
{
	std::string str;
	char i;
	int j;

	std::cout<<"_____________________________________________" << std::endl;
	std::cout<<"|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout<<"|----------|----------|----------|----------|" << std::endl;
	i = '0';
	j = 0;
	while (++i <= '8')
	{
		if(Contact[i - 1 - '0'].get_first_name().size() && ++j)
		{
			str = i;
			str = fix_width(str, 10);
			std::cout<< "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(Contact[i - 1 - '0'].get_first_name(), 10);
			std::cout<< "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(Contact[i - 1 - '0'].get_last_name(), 10);
			std::cout<< "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(Contact[i - 1 - '0'].get_nickname(), 10);
			std::cout<< "|" << add_spaces(10 - str.size()) << str;
			std::cout <<"|" << std::endl;
		}
	}
	std::cout<<"---------------------------------------------" << std::endl;
	return(j);
}
void	PhoneBook::print_one_contact(Contact Contact)
{
	std::cout << std::endl << "Requesting detailed information..." << std::endl;
	if(!Contact.get_first_name().size())
	{
		std::cout << "Failed!" <<std::endl;
		return ;
	}
	std::cout <<"First name: " << Contact.get_first_name() <<std::endl;
	std::cout <<"Last name: " << Contact.get_last_name() <<std::endl;
	std::cout <<"Nickname: " << Contact.get_nickname() <<std::endl; 
	std::cout <<"Phone number: " << Contact.get_phone_number() <<std::endl; 
	std::cout <<"Darkest secret: " << Contact.get_darkest_secret() <<std::endl; 
}

void	PhoneBook::search(void)
{
	std::string str;

	if (!print_list(this->_Contacts))
	{
		std::cout <<"PhoneBook is empty" << std::endl;
		return ;
	}
	while(!std::cin.eof())
	{
		std::cout <<"Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->_Contacts[str[0] - 1 - '0'].get_first_name().size())
				break;
		}
		if (str != "")
			std::cout <<"Invalid index!" <<std::endl;
	}
	if (!std::cin.eof())
		this->print_one_contact(this->_Contacts[str[0] - 1 - '0']);
}
