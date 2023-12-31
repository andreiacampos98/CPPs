#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

# include <iostream>

class Contact{

	private:
		std::string 		_first_name; 
		std::string 		_last_name; 
		std::string 		_nickname; 
		std::string 		_phone_number; 
		std::string 		_darkest_secret;

	public:
		Contact(void);
		~Contact(void);
		void			set_first_name(std::string str);
		void			set_last_name(std::string str);
		void			set_nickname(std::string str);
		void			set_phone_number(std::string str);
		void			set_darkest_secret(std::string str);
		std::string		get_first_name(void);
		std::string		get_last_name(void);
		std::string		get_nickname(void);
		std::string		get_phone_number(void);
		std::string		get_darkest_secret(void);
};

#endif