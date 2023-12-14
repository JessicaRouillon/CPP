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

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

virtual AMateria *AMateria::clone() const
{
	AMateria *tmp = new MateriaSource(*this);

	tmp->setUser(NULL);
	tmp->setSource(NULL);
	return (tmp);
}

virtual void MateriaSource::use(ICharacter &target)
{
	std::cout << "* shoots an MateriaSource bolt at " << target << " *" << std::endl;
}
