#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# include <iostream>

class MateriaSource : public IMateriaSource
{

public:
// Constructors, Destructors, Operators
	MateriaSource();
	MateriaSource(std::string const & type);
	MateriaSource(const MateriaSource& copy);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource& src);

// Functions
	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);

private:

	AMateria*	_source[4];
};

#endif