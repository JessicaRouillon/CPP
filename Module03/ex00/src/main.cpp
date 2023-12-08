#include "ClapTrap.hpp"

int main()
{
	std::cout << "========== TESTING CLAPTRAP ==========\n" << std::endl;
	{
		std::cout << "\033[1;34m\t>> Constructors << \033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Mario");

		std::cout << "\033[1;34m\t>> Actions <<\033[0m" << std::endl;
		a.attack("Boo");
		a.takeDamage(5);
		a.beRepaired(2);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("Waluigi");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Bowser");
		b.beRepaired(3);
		std::cout << "\033[1;34m\t>> Deconstructors <<\033[0m" << std::endl;
	}
	return (0);
}
