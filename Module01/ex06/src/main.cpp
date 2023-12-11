#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		harl_instance;

	if (ac == 2)
		harl_instance.complain(av[1]);
	else
		harl_instance.complain("insignificant problems");
	return (EXIT_SUCCESS);
}
