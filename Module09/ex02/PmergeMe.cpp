#include "PmergeMe.hpp"

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

bool	PMergeMe::isValidInput(const int ac, const char **av)
{
	for (size_t i = 1; i < ac; i++)
	{
		if (this->isValidArg(av[i]) == false)
			return (false);
	}
	return (true);
}


bool	PMergeMe::isValidArg(const char *av)
{
	const char*	base = "0123456789";

	for(size_t i = 0; i != '\0'; i++)
	{
		if (strchr(base, av[i]) == false)
			return (false);
	}
	return (true);
}