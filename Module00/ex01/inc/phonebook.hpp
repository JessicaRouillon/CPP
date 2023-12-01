#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> // std::cout
#include <string>	// std::string
#include <cctype>	// ispalpha, isdigit
#include <iomanip>	// setw
#include <cstdlib>	// atoi
#include <sstream>	// convert string to int

#include "contact.hpp"

class PhoneBook
{

public:
	PhoneBook();  // prototype of constructor
	~PhoneBook(); // prototype of destructor

	size_t add_new_contact(size_t i);
	size_t error_and_erase(size_t i, std::string str);
	void search_contact(void);
	void display_contacts(void) const;
	void print_contact(Contact contact);

	// Getter
	Contact get_contact(int i);

private:
	Contact _contact[8];
};

#endif