#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"

class PhoneBook
{

public:

	PhoneBook(); //prototype of constructor
	~PhoneBook(); //prototype of destructor

	void	add_new_contact(size_t i);
	void	search_contact(size_t i);
	void	print_contacts(Contact contact);

	// Getter
	Contact	get_contact(size_t i);

private:

	Contact	_phonebook[8];
};

#endif