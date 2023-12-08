#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "========== TESTING CLAPTRAP ==========\n"
			  << std::endl;
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
	std::cout << "\n\n========== TESTING SCAVTRAP ==========\n"
			  << std::endl;
	{
		std::cout << "\033[1;34m\t>> Constructors << \033[0m" << std::endl;
		ScavTrap c;
		ScavTrap d("Buttercup");

		std::cout << "\033[1;34m\t>> Actions <<\033[0m" << std::endl;
		c.attack("Huge Lizard Monster");
		// for (int i = 0; i < 50; i++)
		// 	c.attack("Huge Lizard Monster");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(10);
		c.guardGate();
		c.guardGate();
		d.attack("Mojo Jojo");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("Sedusa");
		std::cout << "\033[1;34m\t>> Deconstructors <<\033[0m" << std::endl;
	}
	std::cout << "\n\n========== TESTING FRAGTRAP ==========\n"
			  << std::endl;
	{
		std::cout << "\033[1;34m\t>> Constructors << \033[0m" << std::endl;
		FragTrap e;
		FragTrap f("Samurai Jack");

		std::cout << "\033[1;34m\t>> Actions <<\033[0m" << std::endl;
		e.highFivesGuys();
		e.attack("Aku");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("Aku");
		e.highFivesGuys();
		f.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	f.attack("Demongo");
		std::cout << "\033[1;34m\t>> Deconstructors <<\033[0m" << std::endl;
	}
	return (0);
}
