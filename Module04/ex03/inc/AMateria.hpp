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
	std::string const	&getType() const; //Returns the materia type
	Character* const	&getUser() const;
	MateriaSource* const	&getSource() const;

	void setUser(Character* user);
	void setSource(MateriaSource* source);

// Functions
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target) = 0;

protected:

	std::string		_type;
	Character*		_user;
	MateriaSource*	_source;
	bool			_dropped;
};

#endif