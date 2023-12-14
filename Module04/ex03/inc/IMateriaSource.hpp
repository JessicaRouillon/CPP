#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

# include <iostream>

class IMateriaSource
{

public:
// Constructors, Destructors, Operators
	virtual ~IMateriaSource() {}

// Functions
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif