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

void PhoneBook::add_new_contact(size_t i)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (std::cin.eof() == false)
	{
		if (i >= 7)
		{
			std::cout << "Warning: maximum number of contacts reached (8). Overwriting " << this->_contact[i % 8].get_first_name();
			std::cout << "'s contact information." << std::endl;
		}
		// Get first name from user input
		std::cout << "Type in contact's first name >> ";
		if (std::getline(std::cin, first_name) && first_name != "")
			this->_contact[i % 8].set_first_name(first_name);

		// Check if first name is only letters
		bool all_letters = true;
		for (size_t j = first_name.length(); j >= 0; j--)
		{
			if (!std::isalpha(first_name[i]))
				all_letters = false;
			break;
		}
		if (all_letters == false)
		{
			std::cout << "Incorrect input. First name is letters only" << std::endl;
			return;
		}

		// Get last name from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s last name >> ";
		if (std::getline(std::cin, last_name) && last_name != "")
			this->_contact[i % 8].set_last_name(last_name);

		// Check if last name is only letters
		for (size_t j = last_name.length(); j >= 0; j--)
		{
			if (!std::isalpha(last_name[j]))
				all_letters = false;
			break;
		}
		if (all_letters == false)
		{
			std::cout << "Incorrect input. Last name is letters only" << std::endl;
			return;
		}

		// Get nickname from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s nickname >> ";
		if (std::getline(std::cin, nickname) && nickname != "")
			this->_contact[i % 8].set_nickname(nickname);

		// Get phone number from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s phone number >> ";
		if (std::getline(std::cin, phone_number) && phone_number != "")
			this->_contact[i % 8].set_phone_number(phone_number);

		// Check if phone number is only numbers
		bool all_numbers = true;
		for (size_t j = phone_number.length(); j >= 0; j--)
		{
			if (!std::isdigit(phone_number[j]))
				all_numbers = false;
			break;
		}
		if (all_numbers == false)
		{
			std::cout << "Incorrect input. Phone number is numbers only" << std::endl;
			return;
		}

		// Get darkest secret from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s darkest secret >> ";
		if (std::getline(std::cin, darkest_secret) && darkest_secret != "")
			this->_contact[i % 8].set_darkest_secret(darkest_secret);
	}
}

/***************************** FUNCTION 2 *****************************/

Contact PhoneBook::get_contact(size_t i)
{
	return (this->_contact[i % 8]);
}

/***************************** FUNCTION 3 *****************************/

void PhoneBook::search_contact(size_t i)
{
	std::string index_input;
	int 		index;

	if (this->_contact[0].get_first_name().empty())
	{
		std::cout << "Phonebook is empty for now." << std::endl;
		return;
	}
	else
	{
		this->display_contacts(i);
		while (std::cin.eof() == false)
		{
			std::cout << "Please type in contact Index number to see full information >> ";
			if (std::getline(std::cin, index_input) && index_input != "")
			{
				index = std::stoi(input_index);
				if (index_input.length() == 1 && index >= 1 && index <= 8)
					break;
				else
					std::cout << "Invalid index !" << std::endl;
			}
		}
		if (std::cin.eof() == false)
			this->print_contact(this->get_contact(index));
	}
}


/***************************** FUNCTION 4 *****************************/

void PhoneBook::display_contacts(size_t i)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;

	std::cout << std::endl;
	std::cout << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nickname"
			  << "|" << std::endl;
	for (size_t j = 0; j < (i % 8); j++)
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
		std::cout << std::setw(10) << j + 1 << "|" << std::setw(10) << first_name << "|" << std::setw(10) << last_name << "|" << std::setw(10) << nickname << "|" << std::endl;
	}
	std::cout << std::endl;
}


/***************************** FUNCTION 5 *****************************/

void PhoneBook::print_contact(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First Name : " << contact.get_first_name() << std::endl;
	std::cout << "Last Name : " << contact.get_first_name() << std::endl;
	std::cout << "Nickname : " << contact.get_first_name() << std::endl;
	std::cout << "Phone number : " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << contact.get_darkest_secret() << std::endl;
	return;
}
