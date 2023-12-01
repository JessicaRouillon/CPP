#include "zombie.hpp"

int	main()
{
	Zombie	*zombie = newZombie("Frankenstein");

	zombie->announce();
	randomChump("Bob");
	delete zombie;
	return (EXIT_SUCCESS);
}
