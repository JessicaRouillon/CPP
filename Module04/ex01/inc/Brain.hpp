#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{

public:

	Brain();
	Brain(const Brain& copy);
	~Brain();

	Brain& operator=(const Brain& src);

	void				setIdea(size_t i, std::string idea) const;
	const std::string	get_Idea(size_t i) const;

private:

	std::string		_ideas[100];

};

#endif