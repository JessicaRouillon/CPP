#include "Zombie.hpp"

int	main()
{
	Zombie		*horde;
	int const	zombie_count = 5;

	horde = zombieHorde(zombie_count, "Z-Horder");
	if (horde == NULL)
		return (EXIT_FAILURE);

	for (int i = 0; i < zombie_count; i++)
		horde[i].announce();

	delete[] horde;
	return (EXIT_SUCCESS);
}
