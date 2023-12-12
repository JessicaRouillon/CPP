#include "Zombie.hpp"

int	main()
{
	Zombie		*horde;
	int const	zombie_count = 5;

	if (zombie_count > 10000)
	{
		std::cout << "Too many zombies requested: maximum is 1,000." << std::endl;
		return (EXIT_FAILURE);
	}
	horde = zombieHorde(zombie_count, "Z-Horder");
	if (horde == NULL)
		return (EXIT_FAILURE);

	for (int i = 0; i < zombie_count; i++)
		horde[i].announce();

	delete[] horde;
	return (EXIT_SUCCESS);
}
