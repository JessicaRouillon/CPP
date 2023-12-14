#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <cstdlib>

class DiamondTrap: public ScavTrap, public FragTrap
{

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& copy);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& src);

	void	attack(const std::string& target);
	void	whoAmI(void);

private:

	std::string	_name;
};

#endif