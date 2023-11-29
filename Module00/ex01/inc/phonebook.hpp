#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> // std::cout
#include <string> // std::string
#include <cctype> // ispalpha, isdigit
#include <iomanip> // setw

#include "contact.hpp"

class PhoneBook
{

public:
	PhoneBook();  // prototype of constructor
	~PhoneBook(); // prototype of destructor

	void add_new_contact(size_t i);
	void search_contact(size_t i);
	void display_contacts(size_t i);
	void print_contact(Contact contact);

	// Getter
	Contact get_contact(size_t i);

private:
	Contact _contact[8];
};

#endif