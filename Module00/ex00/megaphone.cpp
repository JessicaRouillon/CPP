#include <iostream>
#include <cstdlib>

int main(int ac, char **av)
{
	std::string const no_arg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string current_arg;

	if (ac == 1)
	{
		std::cout << no_arg << std::endl;
		return (EXIT_SUCCESS);
	}
	for (int i = 1; i < ac; i++)
	{
		current_arg = av[i];
		for (size_t j = 0; j < current_arg.length(); j++)
		{
			std::cout << (char)toupper(current_arg[j]);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
