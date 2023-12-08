#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{

public:

	Cat();
	Cat(const Cat& copy);
	~Cat();

	Cat& operator=(const Cat& src);

private:
		Brain	*_brain;
};

#endif