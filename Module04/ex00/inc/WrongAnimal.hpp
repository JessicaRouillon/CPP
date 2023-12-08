#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <cstdlib>

class WrongAnimal
{

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& src);

	void		makeSound(void) const;
	std::string	getType(void) const;

protected:

	std::string _type;

};

#endif