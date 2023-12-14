#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

# include <iostream>

class AMateria;

class ICharacter : public ICharacter
{

public:
// Constructors, Destructors, Operators
	virtual ~ICharacter() {}

// Getters & Setters
	virtual std::string const & getName() const = 0;

// Functions
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

};

#endif