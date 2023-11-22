#include <iostream>

int main(int ac, char **av)
{
	std::string const no_arg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string arg;

	if (ac == 1)
	{
		std::cout << no_arg << std::endl;
		return;
	}
	for (int i = 1; i < ac; i++)
	{
		arg = av[i];
		for (int j = 0; j < arg.length(); j++)
		{
			std::cout << (char)toupper(arg[j]);
		}
	}
}
