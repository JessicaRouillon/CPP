#include "phonebook.hpp"
#include "contact.hpp"

int main(void)
{
	PhoneBook 	phonebook;
	std::string line;
	size_t 		i;

	i = 0;
	std::cout << std::endl
			  << "     WELCOME TO YOUR PERSONAL PHONEBOOK !" << std::endl
			  << std::endl;
	while (std::cin.eof() == false)
	{
		std::cout << "-------------------------------------------------------------------" << std::endl;
		std::cout << std::endl
				  << "Please type in the option you would like to use for your PhoneBook:" << std::endl
				  << std::endl;
		std::cout << "ADD   /   SEARCH   /   EXIT   >>   ";
		std::getline(std::cin, line);

		if (line == "EXIT")
			return 0;
		else if (line == "ADD")
		{
			phonebook.add_new_contact(i);
			i++;
		}
		else if (line == "SEARCH")
		{
			if (std::cin.eof() == false)
				phonebook.search_contact(i);
		}
		else
		{
			if (std::cin.eof() == false)
			{
				std::cout << "\033[33m";
				std::cout << std::endl << "Only ADD, SEARCH, EXIT are accepted." << std::endl << std::endl;
				std::cout << "\033[0m";
			}
		}
	}
	std::cout << std::endl << std::endl << "Goodbye !" << std::endl;
	return 0;
}
