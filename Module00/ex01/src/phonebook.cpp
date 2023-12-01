#include "phonebook.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructor
PhoneBook::PhoneBook()
{
}

// Destructor
PhoneBook::~PhoneBook()
{
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

/***************************** FUNCTION 1 *****************************/

size_t PhoneBook::add_new_contact(size_t i)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (std::cin.eof() == false)
	{
		std::cout << std::endl;
		std::cout << "i = " << i << "   so Index for this new user = " << i + 1 << std::endl
				  << std::endl;

		// Substitution in case we have reached maximum number of contacts (8)
		if (i > 7)
		{
			std::cout << "\033[33m";
			std::cout << std::endl
					  << "/!\\ Warning: maximum number of contacts reached (8). Overwriting " << this->_contact[i % 8].get_first_name();
			std::cout << "'s contact information." << std::endl;
			std::cout << "\033[0m";
		}

		// Get first name from user input
		std::cout << "Type in contact's first name >> ";
		if (std::getline(std::cin, first_name) && std::cin.eof() == false)
		{
			if (first_name == "")
				return (error_and_erase(i, "/!\\ Incorrect input: First Name cannot be empty."));

			// Check if first name is only letters and spaces
			bool all_letters_first = true;
			for (size_t j = 0; j < first_name.size(); j++)
			{
				if (!std::isalpha((first_name[j])) && !std::isspace(first_name[j]))
				{
					all_letters_first = false;
					break;
				}
			}
			if (all_letters_first == false)
				return (error_and_erase(i, "/!\\ Incorrect input: First name is letters only."));
			else
				this->_contact[i % 8].set_first_name(first_name);
		}

		// Get last name from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s last name >> ";
		if (std::getline(std::cin, last_name) && std::cin.eof() == false)
		{
			if (last_name == "")
				return (error_and_erase(i, "/!\\ Incorrect input: Last Name cannot be empty."));

			// Check if last name is only letters and spaces
			bool all_letters_last = true;
			for (size_t k = 0; k < last_name.size(); k++)
			{
				if (!std::isalpha((last_name[k])) && !std::isspace(last_name[k]))
				{
					all_letters_last = false;
					break;
				}
			}
			if (all_letters_last == false)
				return (error_and_erase(i, "/!\\ Incorrect input: Last name is letters only."));
			else
				this->_contact[i % 8].set_last_name(last_name);
		}

		// Get nickname from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s nickname >> ";
		if (std::getline(std::cin, nickname) && nickname != "" && std::cin.eof() == false)
			this->_contact[i % 8].set_nickname(nickname);
		else
			return (error_and_erase(i, "/!\\ Incorrect input: Nickname cannot be empty."));

		// Get phone number from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s phone number >> ";
		if (std::getline(std::cin, phone_number) && std::cin.eof() == false)
		{
			if (phone_number == "")
				return (error_and_erase(i, "/!\\ Incorrect input: Phone Number cannot be empty."));

			// Check if phone number is only numbers and spaces
			bool all_numbers = true;
			for (size_t l = 0; l < phone_number.size(); l++)
			{
				if (!std::isdigit(phone_number[l]) && !std::isspace(phone_number[l]))
				{
					all_numbers = false;
					break;
				}
			}
			if (all_numbers == false)
				return (error_and_erase(i, "/!\\ Incorrect input: Phone Number is numbers only."));
			else
				this->_contact[i % 8].set_phone_number(phone_number);
		}

		// Get darkest secret from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s darkest secret >> ";
		if (std::getline(std::cin, darkest_secret) && darkest_secret != "" && std::cin.eof() == false)
		{
			this->_contact[i % 8].set_darkest_secret(darkest_secret);
			std::cout << "\033[32m";
			std::cout << std::endl
					  << "Contact added !" << std::endl;
			std::cout << "\033[0m";
			return (i + 1);
		}
		else
			return (error_and_erase(i, "/!\\ Incorrect input: Darkest Secret cannot be empty."));
	}
	return (i + 1);
}

/***************************** FUNCTION 2 *****************************/

size_t PhoneBook::error_and_erase(size_t i, std::string str)
{
	// Print error message
	std::cout << "\033[33m";
	std::cout << std::endl
			  << str << std::endl
			  << std::endl;
	std::cout << "\033[0m";

	// Delete all of the contact's information
	this->_contact[i % 8].set_first_name("");
	this->_contact[i % 8].set_last_name("");
	this->_contact[i % 8].set_nickname("");
	this->_contact[i % 8].set_phone_number("");
	this->_contact[i % 8].set_darkest_secret("");
	return i;
}

/***************************** FUNCTION 3 *****************************/

void PhoneBook::search_contact(void)
{
	std::string index_input;
	std::istringstream iss;
	int index;

	if (this->_contact[0].get_first_name().empty())
	{
		std::cout << std::endl;
		std::cout << "Phonebook is empty for now." << std::endl;
		std::cout << std::endl;
		return;
	}
	else
	{
		this->display_contacts();
		while (std::cin.eof() == false)
		{
			std::cout << "Please type in contact Index number to see full information >> ";
			if (std::getline(std::cin, index_input) && index_input != "")
			{
				if (index_input.length() == 1 && index_input[0] >= '1' && index_input[0] <= '8')
				{
					iss.str(index_input);
					iss >> index;
					break;
				}
				else
				{
					std::cout << "\033[33m";
					std::cout << " /!\\ Invalid index !" << std::endl;
					std::cout << "\033[0m";
				}
			}
		}
		if (std::cin.eof() == false)
			this->print_contact(this->get_contact(index - 1));
	}
}

/***************************** FUNCTION 4 *****************************/

Contact PhoneBook::get_contact(int i)
{
	return (this->_contact[i % 8]);
}

/***************************** FUNCTION 5 *****************************/

void PhoneBook::display_contacts(void) const
{
	std::string first_name;
	std::string last_name;
	std::string nickname;

	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nickname"
			  << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "----------"
			  << "|" << std::setw(10) << "----------"
			  << "|" << std::setw(10) << "----------"
			  << "|" << std::setw(10) << "----------"
			  << "|" << std::endl;

	for (size_t j = 0; j < 8; j++)
	{
		first_name = this->_contact[j].get_first_name();
		last_name = this->_contact[j].get_last_name();
		nickname = this->_contact[j].get_nickname();
		if (first_name.length() > 10)
		{
			first_name.resize(9);
			first_name.resize(10, '.');
		}
		if (last_name.length() > 10)
		{
			last_name.resize(9);
			last_name.resize(10, '.');
		}
		if (nickname.length() > 10)
		{
			nickname.resize(9);
			nickname.resize(10, '.');
		}
		std::cout << "|" << std::setw(10) << j + 1
				  << "|" << std::setw(10) << first_name
				  << "|" << std::setw(10) << last_name
				  << "|" << std::setw(10) << nickname
				  << "|" << std::endl;
	}
	std::cout << std::endl;
}

/***************************** FUNCTION 6 *****************************/

void PhoneBook::print_contact(Contact contact)
{
	std::cout << std::endl;
	if (contact.get_first_name().empty())
	{
		std::cout << "\033[33m";
		std::cout << "/!\\ No contact registered with selected index." << std::endl;
		std::cout << "\033[0m";
	}
	else
	{
		std::cout << "First Name : " << contact.get_first_name() << std::endl;
		std::cout << "Last Name : " << contact.get_last_name() << std::endl;
		std::cout << "Nickname : " << contact.get_nickname() << std::endl;
		std::cout << "Phone number : " << contact.get_phone_number() << std::endl;
		std::cout << "Darkest secret : " << contact.get_darkest_secret() << std::endl;
	}
}
