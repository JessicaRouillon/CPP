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


bool		PMergeMe::isOddArgs(const int& ac)
{
	if ((ac - 1) % 2 != 0)
	{
		_isOdd = true;
		return (true);
	}
	_isOdd = false;
	return (false);
}


std::deque<std::deque<int>>	PMergeMe::createPairs(const std::vector<int>& vec)
{
	std::deque<std::deque<int>>		pairedArray;
	std::deque<int>					tmpArray;

	for (size_t i = 0; i < vec.size(); i++)
	{
		size_t	tmpSize = tmpArray.size();
		if (tmpArray.size() == 1)
		{
			
		}

	}
}



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

	/******************************* INITIALIZATION *******************************/

	std::vector<int>	vec;

	std::cout << "Before : ";
	for (size_t i = 1; i < ac; i++)
	{
		vec.push_back(atoi(av[i]));

		std::cout << av[i];
		if (i < ac - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}

	/******************************* FIND STRAGGLER *******************************/

	bool	isOddArgs = this->isOddArgs(ac);
	if (isOddArgs == true)
	{
		_straggler = vec.back();
		vec.pop_back();
	}

	/******************************** CREATE PAIRS ********************************/

	std::deque<std::deque<int>>		deq = this->createPairs(vec);
	
}
