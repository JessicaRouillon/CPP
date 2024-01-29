#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange	obj;
		obj.execute(av[1]);
	}
	else
		std::cout << "\033[0;31mError: Invalid number of arguments.\033[0m" << std::endl;
	return (0);
}
