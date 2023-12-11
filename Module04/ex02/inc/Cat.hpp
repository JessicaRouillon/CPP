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

	void	makeSound(void) const;
	void	getIdeas(void) const;
	void	setIdea(const size_t i, const std::string idea);

private:
		Brain	*_brain;
};

#endif