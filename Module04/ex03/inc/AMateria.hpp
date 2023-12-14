#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Character.hpp"

# include <iostream>

class Character;
class ICharacter;
class MateriaSource;
class IMateriaSource;

class AMateria
{

public:
// Constructors, Destructors, Operators
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& src);

// Getters & Setters
	std::string const		&getType() const; //Returns the materia type

// Functions
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:

	std::string		_type;

};

#endif