#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>

class ScavTrap: virtual public ClapTrap
{

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap();

	void	attack(const std::string& target);
	void	beRepaired(unsigned int amount);
	void	guardGate(void);

private:

	bool 	_guarding_gate;

};

#endif