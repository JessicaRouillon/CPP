#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# include <iostream>

class Ice : public AMateria
{

public:
// Constructors, Destructors, Operators
	Ice();
	Ice(std::string const & type);
	Ice(const Ice& copy);
	virtual ~Ice();

	Ice& operator=(const Ice& src);

// Functions
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif