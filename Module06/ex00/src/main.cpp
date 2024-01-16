#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter converter;
		std::string		str(av[1]);

		converter.setString(str);
		converter.setType(str);
		std::cout << "Type = " << converter.getType() << std::endl;  // A retirer
		try
		{
			converter.convert();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	else
		std::cout << "\033[0;31mInvalid number of arguments.\033[0m" << std::endl;
	return (0);
}
