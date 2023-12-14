#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

# include <iostream>

class Cure : public AMateria
{

public:
// Constructors, Destructors, Operators
	Cure();
	Cure(std::string const & type);
	Cure(const Cure& copy);
	virtual ~Cure();

	Cure& operator=(const Cure& src);

// Functions
	virtual Cure *clone() const;
	virtual void use(ICharacter &target);
};

#endif