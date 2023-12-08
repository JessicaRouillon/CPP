#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{

public:

	Dog();
	Dog(const Dog& copy);
	~Dog();

	Dog& operator=(const Dog& src);

private:
		Brain	*_brain;

};

#endif