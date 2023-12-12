#include "Harl.hpp"

int	main()
{
	Harl	harl_instance;

	std::cout << std::endl << "Here are all the things Harl can say :" << std::endl << std::endl;
	harl_instance.complain("DEBUG");
	std::cout << std::endl;
	harl_instance.complain("INFO");
	std::cout << std::endl;
	harl_instance.complain("WARNING");
	std::cout << std::endl;
	harl_instance.complain("ERROR");
	std::cout << std::endl;
	std::cout << "\033[1;32m" << "Now try it yourself ! Use exit or EXIT to close program." << "\033[0m" << std::endl;

	std::string		input;
	while (std::cin.eof() == false)
	{
		std::cout << std::endl << "\033[1m"  << "Type in DEBUG, INFO, WARNING or ERROR >> " << "\033[0m";
			if (std::getline(std::cin, input))
			{
				if (input == "DEBUG")
					harl_instance.complain("DEBUG");
				else if (input == "INFO")
					harl_instance.complain("INFO");
				else if (input == "WARNING")
					harl_instance.complain("WARNING");
				else if (input == "ERROR")
					harl_instance.complain("ERROR");
				else if (input == "exit" || input == "EXIT")
					return (EXIT_SUCCESS) ;
				else
					std::cout << std::endl << "\033[33m" << "/!\\ Incorrect input." << "\033[0m";
				std::cout << std::endl;
			}
		if (std::cin.eof() == true)
		{
			std::cerr << "^D" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
