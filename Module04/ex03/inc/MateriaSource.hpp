#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"

# include <iostream>

class MateriaSource : public AMateria
{

public:
// Constructors, Destructors, Operators
	MateriaSource();
	MateriaSource(std::string const & type);
	MateriaSource(const MateriaSource& copy);
	virtual ~MateriaSource();

	MateriaSource& operator=(const MateriaSource& src);

// Getters & Setters
	void	setMemory(size_t i) const;
	AMateria const	*getMemory(size_t i, AMateria *materia);

// Functions

private:

	AMateria*	_memory[4];
};

#endif