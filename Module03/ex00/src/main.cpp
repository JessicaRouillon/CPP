#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	claptrap("Bloop");
	claptrap.attack("Loser");
	claptrap.takeDamage(2);
	claptrap.beRepaired(5);
	claptrap.attack("Loser");
	claptrap.takeDamage(5);
	claptrap.beRepaired(2);
	claptrap.takeDamage(4);
	claptrap.attack("Loser");
	claptrap.beRepaired(2);
	claptrap.takeDamage(5);
	claptrap.attack("Loser");
	claptrap.beRepaired(2);
	claptrap.takeDamage(5);
	return (EXIT_SUCCESS);
}
