#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream> // std::cout
#include <string>	// std::string
#include <cctype>	// ispalpha, isdigit
#include <iomanip>	// setw
#include <sstream>	// convert string to int

class Contact
{

public:
	Contact();	// prototype of constructor
	~Contact(); // prototype of destructor

	// Setters - to define the attributes
	void set_first_name(std::string str);
	void set_last_name(std::string str);
	void set_nickname(std::string str);
	void set_phone_number(std::string str);
	void set_darkest_secret(std::string str);

	// Getters - to display the attributes
	std::string get_first_name(void) const;
	std::string get_last_name(void) const;
	std::string get_nickname(void) const;
	std::string get_phone_number(void) const;
	std::string get_darkest_secret(void) const;

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif