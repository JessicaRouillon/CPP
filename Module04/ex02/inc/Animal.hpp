#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal
{

public:
	Animal(const Animal &copy);
	virtual ~Animal();

	Animal &operator=(const Animal &src);

	std::string		getType(void) const;
	virtual void	makeSound(void) const = 0;

protected:
	Animal();
	std::string _type;
};

#endif