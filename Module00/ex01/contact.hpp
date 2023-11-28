#ifndef CONTACT_H
#define CONTACT_H

#include "main.hpp"

class Contact
{

public:

	Contact(); //prototype of constructor
	~Contact(); //prototype of destructor

	// Getters - to display them
	std::string get_first_name(void)const;
	std::string get_last_name(void)const;
	std::string get_nickname(void)const;
	std::string get_phone_number(void)const;
	std::string get_darkest_secret(void)const;

	// Setters - to define them
	void	set_first_name(std::string str);
	void	set_last_name(std::string str);
	void	set_nickname(std::string str);
	void	set_phone_number(std::string str);
	void	set_darkest_secret(std::string str);


private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

};

#endif