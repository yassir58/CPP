#ifndef _PHONE_BOOK_H
#define _PHONE_BOOK_H


#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

class Contact
{
	public:
		int indx;
		std::string first_name;
		std::string last_name;
		std::string phone_number;
		std::string darkest_secret;
		std::string nickname;
	public:
		void set_contact_info (std::string first_name, std::string last_name,
			 std::string phone, std::string secret, std::string nickname);
		std::string get_contact_info (int indx);
	public:
		Contact ();
};

class PhoneBook 
{
	public:
		int indx;
		Contact contacts[8];
		int length;
	public:
		Contact get_contact (int index) const;
		void 	set_contact (Contact contact);	
	public:
		PhoneBook ();
};

#endif