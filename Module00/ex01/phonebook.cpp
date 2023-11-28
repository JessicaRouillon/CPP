#include "main.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructor
PhoneBook::PhoneBook()
{
	std::cout << "WELCOME TO YOUR PERSONAL PHONEBOOK !" << std::endl;
	std::cout << std::endl;
}

// Destructor
PhoneBook::~PhoneBook()
{
	std::cout << "Goodbye !" << std::endl;
}


/********************************************************************************/
/*********************************** FUNCTIONS **********************************/
/********************************************************************************/

/***************************** FUNCTION 1 *****************************/

void	PhoneBook::add_new_contact(size_t i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	while (std::cin.eof() == false)
	{
		if (i >= 7)
		{
			std::cout << "Warning: maximum number of contacts reached (8). Overwriting " << this->_phonebook[i % 8].get_first_name();
			std::cout << "'s contact information." << std::endl;
			i = i % 8;
		}
		// Get first name from user input
		std::cout << "Type in contact's first name >> ";
		if (std::getline(std::cin, first_name) && first_name != "")
			this->_phonebook[i % 8].set_first_name(first_name);

			// Check if first name is only letters
		bool	all_letters = true;
		for (char c : first_name)
		{
			if (!std::isalpha(c))
				all_letters = false;
				break;
		}
		if (all_letters == false)
			return ;

		// Get last name from user input
		std::cout << "Type in " << this->_phonebook[i % 8].get_first_name() <<"'s last name >> ";
		if (std::getline(std::cin, last_name) && last_name != "")
			this->_phonebook[i % 8].set_last_name(last_name);

			// Check if last name is only letters
		bool	all_letters = true;
		for (char c : last_name)
		{
			if (!std::isalpha(c))
				all_letters = false;
				break;
		}
		if (all_letters == false)
			return ;

		// Get nickname from user input
		std::cout << "Type in " << this->_phonebook[i % 8].get_first_name() <<"'s nickname >> ";
		if (std::getline(std::cin, nickname) && nickname != "")
			this->_phonebook[i % 8].set_nickname(nickname);

		// Get phone number from user input
		std::cout << "Type in " << this->_phonebook[i % 8].get_first_name() <<"'s phone number >> ";
		if (std::getline(std::cin, phone_number) && phone_number != "")
			this->_phonebook[i % 8].set_phone_number(phone_number);

			// Check if phone number is only numbers
		bool	all_numbers = true;
		for (int i : phone_number)
		{
			if (!std::isalnum(i))
				all_numbers = false;
				break;
		}
		if (all_numbers == false)
			return ;

		// Get darkest secret from user input
		std::cout << "Type in " << this->_phonebook[i % 8].get_first_name() <<"'s darkest secret >> ";
		if (std::getline(std::cin, darkest_secret) && darkest_secret != "")
			this->_phonebook[i % 8].set_darkest_secret(darkest_secret);
	}
}


/***************************** FUNCTION 2 *****************************/

Contact	PhoneBook::get_contact(size_t i)
{
	return (this->_phonebook[i % 8]);
}


/***************************** FUNCTION 3 *****************************/

void	PhoneBook::search_contact(void)
{
	std::string		index;

	
}

