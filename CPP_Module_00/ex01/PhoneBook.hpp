#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

#include <iostream>
using namespace std;

class Contact{

	public: 
	string 		first_name; 
	string 		last_name; 
	string 		nickname; 
	string 		phone_number; 
	string 		darkest_secret;

	void	display(void)
	{

	}

};

class PhoneBook{

	public:
	Contact Cons[8];
	int	num;
};

#endif