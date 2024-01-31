#include "PmergeMe.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

PMergeMe &PMergeMe::operator=(const PMergeMe &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// PUBLIC

bool	PMergeMe::isValidInput(const int ac, const char **av)
{
	for (size_t i = 1; i < ac; i++)
	{
		if (this->isValidArg(av[i]) == false)
			return (false);
	}
	return (true);
}


void	PMergeMe::sort(const int ac, const char **av)
{
	std::vector<int>	vec;
	std::deque<int>		deq;

	std::cout << "Before : ";
	for (size_t i = 0; i < ac; i++)
	{
		vec.push_back(atoi(av[i]));
		deq.push_back(atoi(av[i]));

		std::cout << av[i];
		if (i < ac - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}


// PRIVATE

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

