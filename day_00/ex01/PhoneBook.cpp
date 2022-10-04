#include "PhoneBook.h"


PhoneBook::PhoneBook()
{
	indx = 0;
	length = 0;
}

Contact::Contact(){
	first_name = "";
	last_name = "";
	phone_number = "";
	darkest_secret = "";
	nickname = "";
}

void PhoneBook::set_contact(Contact contact)
{
	if (this->indx == 8)
	{
		this->indx=0;
		contact.indx = 0;
	}
	if (this->length < 8)
		this->length++;
	this->contacts[this->indx] = contact;
	this->indx++;
}

Contact create_contact (int index)
{
	Contact contact;

	contact.indx = index;
	while (!strcmp(contact.first_name.c_str(), "") && !std::cin.eof())
		std::cout<<"first name: ", getline (std::cin, contact.first_name);
	while (!strcmp (contact.last_name.c_str(), "") && !std::cin.eof())
		std::cout<<"last name: " , getline (std::cin, contact.last_name);
	while (!strcmp (contact.phone_number.c_str(), "") && !std::cin.eof())
		std::cout<<"phone number: ", getline (std::cin, contact.phone_number);
	while (!strcmp (contact.darkest_secret.c_str(), "") && !std::cin.eof())
		std::cout<<"darkest secret: ", getline (std::cin, contact.darkest_secret);
	while (!strcmp (contact.nickname.c_str(), "") && !std::cin.eof())
		std::cout<<"nickname: ", getline (std::cin, contact.nickname);
	return (contact);
}

void print_contact (Contact contact)
{
	std::cout<<"|", std::cout<< std::setw(10) <<contact.indx;
	std::cout<<"|", std::cout<< std::setw(10) << (contact.first_name.length() < 10 ? contact.first_name:contact.first_name.substr(0, 9)+ ".");
	std::cout<<"|", std::cout<<  std::setw(10)<< (contact.last_name.length() < 10 ? contact.last_name:contact.last_name.substr(0, 9)+ ".");
	std::cout<<"|", std::cout<< std::setw(10) << (contact.nickname.length() < 10 ? contact.nickname:contact.nickname.substr(0, 9) + ".");
	std::cout<<"|"<<std::endl;
}

void display_contact (Contact contact)
{
	std::cout<<contact.first_name<<std::endl;
	std::cout<<contact.last_name<<std::endl;
	std::cout<<contact.phone_number<<std::endl;
	std::cout<<contact.darkest_secret<<std::endl;
	std::cout<<contact.nickname<<std::endl;
}

void print_all(PhoneBook phonebook)
{
	if (phonebook.indx == 0)
		std::cout<<"there is no saved contacts"<<std::endl;
	else
	{
		for (int i = 0; i < phonebook.length;i++)
			print_contact (phonebook.get_contact(i));
	}
}

Contact PhoneBook::get_contact (int indx) const
{
		return (this->contacts[indx]);
}

int main (void)
{
	PhoneBook phonebook;
	int flag = 1;
	int indx = 0;
	std::string line;
	
	while (flag && !std::cin.eof())
	{
		std::cout<< "ENTER COMMAND : ", getline(std::cin, line);
		if (!line.compare("ADD"))
			phonebook.set_contact (create_contact (phonebook.indx));
		else if (!line.compare("SEARCH"))
		{
			print_all (phonebook);
			if (phonebook.indx > 0)
			{
				std::cout<<"contact index: ", getline (std::cin, line), indx = atoi(line.c_str());
				if (indx >= phonebook.indx)
					std::cout<<"index out of range !"<< std::endl;
				else
					display_contact (phonebook.get_contact (indx));
			}
		}
		else if (!line.compare("EXIT"))
			flag = 0;
		else if (line.compare(""))
			std::cout<<"not a valid command !"<<std::endl;
	}
}