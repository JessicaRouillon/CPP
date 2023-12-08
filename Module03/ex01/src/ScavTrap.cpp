#include "ScavTrap.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructors

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap has entered the battlefield (default constructor)." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap " << this->_name << " has entered the battlefield." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "ScavTrap " << this->_name << "'s copy has entered the battlefield." << std::endl;
	this->_guarding_gate = copy._guarding_gate;
}

// Destructor

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has died or left the battlefiled." << std::endl;
}

// Move assignment operator: Overloaded operators
ScavTrap	&ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap " << this->_name << "'s copy assignment operator has entered the battlefield." << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Attack
void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " does not have enough Energy Points to attack." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot attack because he is dead." << std::endl;
}

// Take Damage
void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (this->_hitPoints > amount)
		{
			this->_hitPoints -= amount;
			std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		}
		else
		{
			this->_hitPoints = 0;
			std::cout << "ScavTrap " << this->_name << " has lost all of it's Hit Points!" << std::endl;
		}
	}
	else
		std::cout << "ScavTrap " << this->_name << " cannot take damage because he is already dead." << std::endl;
}

// Be Repaired
void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0 && this->_hitPoints + amount <= 100)
	{
		std::cout << "ScavTrap " << this->_name << " has been repaired and gained " << amount << " Hit Points!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	else if (this->_hitPoints + amount > 100)
		std::cout << "ScavTrap " << this->_name << " cannot heal to have more than 100 Hit Points." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " does not have enough Energy Points to be repaired." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot be repaired because he is dead." << std::endl;
}

// Guard Gate
void	ScavTrap::guardGate(void)
{
	if (this->_guarding_gate == false)
	{
		this->_guarding_gate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate." << std::endl;
}
