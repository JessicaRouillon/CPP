#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

// # define nb_obj	10

class Brain
{

public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &src);

	void setIdea(const size_t i, const std::string idea);
	std::string getIdea(const size_t i);

private:
	std::string _ideas[100];
};

#endif