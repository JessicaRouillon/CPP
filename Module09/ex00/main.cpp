#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange	obj;

		if (obj.getError() == false)
		{
			try {
				obj.execute(av[1]);
			}
			catch(const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
	else
		std::cout << "\033[0;31mError: Invalid number of arguments.\033[0m" << std::endl;
	return (EXIT_SUCCESS);
}
