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
		std::cout << std::endl;

		// Substitution in case we have reached maximum number of contcts (8)
		if (i >= 7)
		{
			std::cout << "\033[33m";
			std::cout << std::endl << "/!\\ Warning: maximum number of contacts reached (8). Overwriting " << this->_contact[i % 8].get_first_name();
			std::cout << "'s contact information." << std::endl;
			std::cout << "\033[0m";
		}


		// Get first name from user input
		while (1)
		{
			std::cout << "Type in contact's first name >> ";
			if (std::getline(std::cin, first_name) && first_name != "")
			{
					// Check if first name is only letters
					bool all_letters_first = true;
					for (size_t j = 0; j < first_name.size(); j++)
					{
						if (!std::isalpha((first_name[j])))
						{
							all_letters_first = false;
							break ;
						}
					}
					if (all_letters_first == false)
					{
						std::cout << "\033[33m";
						std::cout << std::endl << "/!\\ Incorrect input: First name is letters only." << std::endl << std::endl;
						std::cout << "\033[0m";
					}
					else
					{
						this->_contact[i % 8].set_first_name(first_name);
						break ;
					}
			}
		}


		// Get last name from user input
		while (1)
		{
			std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s last name >> ";
			if (std::getline(std::cin, last_name) && last_name != "")
			{
				// Check if last name is only letters
				bool all_letters_last = true;
				for (size_t k = 0; k < last_name.size(); k++)
				{
					if (!std::isalpha((last_name[k])))
					{
						all_letters_last = false;
						break ;
					}
				}
				if (all_letters_last == false)
				{
					std::cout << "\033[33m";
					std::cout << std::endl << "/!\\ Incorrect input: Last name is letters only." << std::endl << std::endl;
					std::cout << "\033[0m";
				}
				else
				{
					this->_contact[i % 8].set_last_name(last_name);
					break ;
				}
			}
		}


		// Get nickname from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s nickname >> ";
		if (std::getline(std::cin, nickname) && nickname != "")
			this->_contact[i % 8].set_nickname(nickname);


		// Get phone number from user input
		while (1)
		{
			std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s phone number >> ";
			if (std::getline(std::cin, phone_number) && phone_number != "")
			{
				// Check if phone number is only numbers
				bool all_numbers = true;
				for (size_t l = 0; l < phone_number.size(); l++)
				{
					if (!std::isdigit(phone_number[l]))
					{
						all_numbers = false;
						break ;
					}
				}
				if (all_numbers == false)
				{
					std::cout << "\033[33m";
					std::cout << std::endl << "/!\\ Incorrect input: Phone number is numbers only." << std::endl << std::endl;
					std::cout << "\033[0m";
				}
				else
				{
					this->_contact[i % 8].set_phone_number(phone_number);
					break ;
				}
			}
		}


		// Get darkest secret from user input
		std::cout << "Type in " << this->_contact[i % 8].get_first_name() << "'s darkest secret >> ";
		if (std::getline(std::cin, darkest_secret) && darkest_secret != "")
		{
			this->_contact[i % 8].set_darkest_secret(darkest_secret);
			std::cout << "\033[32m";
			std::cout << std::endl << "Contact added !" << std::endl;
			std::cout << "\033[0m";
		}
		return;
	}
}

/***************************** FUNCTION 2 *****************************/

void PhoneBook::search_contact(size_t i)
{
	std::string 		index_input;
	std::istringstream	iss;
	int					index;

	if (this->_contact[0].get_first_name().empty())
	{
		std::cout << std::endl;
		std::cout << "Phonebook is empty for now." << std::endl;
		std::cout << std::endl;
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

/***************************** FUNCTION 3 *****************************/

Contact PhoneBook::get_contact(int i)
{
	return (this->_contact[i % 8]);
}

/***************************** FUNCTION 4 *****************************/

void PhoneBook::display_contacts(size_t i)
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
		std::cout << "|" << std::setw(10) << j + 1
				  << "|" << std::setw(10) << first_name
				  << "|" << std::setw(10) << last_name
				  << "|" << std::setw(10) << nickname
				  << "|" << std::endl;
	}
	std::cout << std::endl;
}

/***************************** FUNCTION 5 *****************************/

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
