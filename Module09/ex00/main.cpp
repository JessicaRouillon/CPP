#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			BitcoinExchange	obj("", DATA);
		else
			BitcoinExchange	obj(av[1], DATA);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << NC << std::endl;
	}
	return (0);
}