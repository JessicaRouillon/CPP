#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		// std::string		str = av[1];
		ScalarConverter	convert(av[1]);
	}
	else
		std::cout << "\033[0;31mInvalid number of arguments.\033[0m" << std::endl;
	return (0);
}