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

// int main()
// {
// 	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
// 	{
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		ClapTrap a("Ben");
// 		ClapTrap b("Cody");

// 		std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		a.attack("some other robot");
// 		a.takeDamage(10);
// 		a.takeDamage(10);
// 		a.beRepaired(5);
// 		a.attack("some other other robot");
// 		b.beRepaired(3);
// 		for (int i = 0; i < 12; i++)
// 			b.attack("Cody-clone");
// 		b.beRepaired(3);
// 		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 	}
// 	return (0);
// }
