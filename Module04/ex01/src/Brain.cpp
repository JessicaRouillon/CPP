#include "Brain.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Brain::Brain()
{
	std::cout << "Brain is born." << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy is born." << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain has died." << std::endl;
}

Brain	&Brain::operator=(const Brain& src)
{
	std::cout << "Brain overload operator called." << std::endl;
	if (this != &src)
	{
		for (size_t i = 0; i < 100; i++)
		{
			if (src._ideas[i][0] != NULL)
				this->_ideas[i].assign(src._ideas[i]);
		}
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

const void	Brain::setIdea(size_t i, std::string idea) const
{
	if (i > 100)
		std::cout << "There are only 100 ideas in Brain." << std::endl;
	else
		this->_ideas[i] = idea;
}

const std::string	Brain::getIdea(size_t i)
{
	if (i > 100)
	{
		std::cout << "There are only 100 ideas in Brain." << std::endl;
		return (NULL);
	}
	else
		return (this->_ideas[i]);
}
