#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

#include "Contact.hpp"
#include <iostream>

class PhoneBook{

	private:
		Contact Contacts[8];
		int	index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
		void	print_one_contact(Contact Contact);
};

#endif