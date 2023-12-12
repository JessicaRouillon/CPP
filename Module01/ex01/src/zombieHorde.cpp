#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	if (N < 2)
	{
		std::cout << "Insufficient number of zombies to create a horde." << std::endl;
		return (NULL);
	}

	Zombie	*horde = new Zombie[N];
	if (horde == NULL)
	{
		std::cout << "Horde allocation error." << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}
