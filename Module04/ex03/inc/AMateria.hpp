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
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& src);
	virtual ~AMateria();

	std::string const	&getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:

	std::string		_type;
	bool			_dropped;
};

#endif