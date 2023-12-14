#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# include <iostream>

class Character : public ICharacter
{

public:
// Constructors, Destructors, Operators
	Character();
	Character(std::string name);
	Character(const Character& copy);
	virtual ~Character();

	Character& operator=(const Character& src);

// Getters & Setters
	void				setName(std::string name);
	void				setInventory(size_t i, AMateria* materia);
	const std::string&	getName( void ) const;
	const AMateria*	getInventory(size_t i) const;

// Functions
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:

	std::string		_name;
	AMateria*		_inventory[4];
};

#endif