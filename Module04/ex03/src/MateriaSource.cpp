#include "MateriaSource.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		this->_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (copy._memory[i])
		{
			this->_memory[i] = copy._memory[i]->clone();
			this->_memory[i]->setMateriaSource(this);
		}
		else
			this->_memory[i] = NULL;
	}
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_memory[i])
			delete this->_memory[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters & Setters
void	MateriaSource::setMemory(size_t i, AMateria *materia) const
{
	if (i < 1 || i > 3)
		return ;
	this->_memory[i] = materia;
}

AMateria const	*MateriaSource::getMemory(size_t i)
{
	if (i < 1 || i > 3)
		return ;
	return (this->_memory[i]);
}

// Functions
void	MateriaSource::learnMateria(AMateria* materia)
{
	for(size_t i =0; i < 4; i++)
	{
		if (this->_memory[i] == NULL)
		{
			this->_memory[i] = materia;
			materia->setMaterialSource(this);
			std::cout << "Materia Source has learned " << materia->getType() << "." << std::endl;
			return ;
		}
	}
	std::cout << "Materia Source could not learn " <<  materia->getType() << "." << std::endl;
}

AMateria*	createMateria(std::string const & type)
{
	for (size_t i = 3; i >= 0; i--)
	{
		if (this->_memory[i] && this->_memory[i].getType == type)
		{
			std::cout >> "Materia Source has created " << type << " materia." << std::endl;
			return (this->_memory[i]->clone());
		}
	}
	std::cout << "Materia Source could not create " <<  type << "." << std::endl;
}
