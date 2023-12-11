#include "Cat.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Cat::Cat()
{
	std::cout << "Cat is born into the world." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cout << "Brain allocation error for Cat." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Copy of Cat is born into the world." << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat has died." << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat& src)
{
	std::cout << "Cat overload operator (=) has been set." << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain();
		if (this->_brain == NULL)
		{
			std::cout << "Brain allocation error for Cat overload operator." << std::endl;
			exit(1);
		}
		*this->_brain = *src._brain;
	}
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Cat::makeSound(void) const
{
	std::cout << "The " << this->getType() << " says **MEEOOWWW** !" << std::endl;
}

void	Cat::getIdeas(void) const
{
	for (size_t i = 0; this->_brain->getIdea(i).empty() == false; i++)
		std::cout << "Idea #" << i << " of Cat is >> " << this->_brain->getIdea(i) << "<<" << std::endl;
}

void	Cat::setIdea(const size_t i, const std::string idea)
{
	this->_brain->setIdea(i, idea);
}
