#include "Zombie.hpp"

int	main()
{
	Zombie		*horde;
	int const	zombie_count = 10;

	horde = zombieHorde(zombie_count, "Z-Horder");
	if (horde == NULL)
		return (EXIT_FAILURE);
	for (int i = 0; i < zombie_count; i++)
		horde[i].announce();
	delete[] horde;
	// horde = zombieHorde(0, "Failed");
	return (EXIT_SUCCESS);
}
