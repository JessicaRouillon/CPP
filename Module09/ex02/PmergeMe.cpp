#include "PmergeMe.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include "PmergeMe.hpp"

template <template<typename, typename> class Container>
PMergeMe<Container>::PMergeMe(char **av): _time(0)
{
	_straggler = -1;

	for(size_t i = 0; av[i]; i++)
	{
		if (isValidArg(av[i]) == false)
			throw (std::invalid_argument("\033[0;31mError: Invalid input\033[0m"));
		_data.push_back(atoi(av[i]));
	}
	if ((_data.size() % 2) != 0)
	{
		_straggler = _data.back();
		_data.erase(_data.end() - 1);
	}
}


template <template<typename, typename> class Container>
PMergeMe<Container>::PMergeMe(const PMergeMe<Container> &copy)
{
	_data = copy._data;
	_time = copy._time;
	_straggler = copy._straggler;
}


template <template<typename, typename> class Container>
PMergeMe<Container> &PMergeMe<Container>::operator=(const PMergeMe<Container> &src)
{
	if (this != &src)
	{
		_data = src._data;
		_time = src._time;
		_straggler = src._straggler;
	}
	return (*this);
}


/********************************************************************************/
/************************* PRIVATE MEMBER FUNCTIONS *****************************/
/********************************************************************************/



template <template<typename, typename> class Container>
bool	PMergeMe<Container>::isValidArg(const char *av)
{
	const char	*base = "0123456789";

	for(size_t i = 0; av[i]; i++)
	{
		if (!strchr(base, av[i]))
			return (false);
	}
	return (true);
}




/********************************************************************************/
/************************* PUBLIC MEMBER FUNCTIONS ******************************/
/********************************************************************************/



template <template<typename, typename> class Container>
void	PMergeMe<Container>::printData() const
{
	for(size_t i = 0; i < _data.size(); i++)
		std::cout << _data[i] << " ";
	if (_straggler >= 0)
		std::cout << _straggler;
	std::cout << std::endl;
}



template <template<typename, typename> class Container>
void	PMergeMe<Container>::sort()
{
	// clock_t	startTime = clock();

	/******************************** CREATE PAIRS ********************************/

	typename	Container< int, std::allocator<int> >::iterator	it;

	for (it = _data.begin(); it != _data.end(); it += 2)
	{
		if (it[0] > it[1])
			std::iter_swap(it, it + 1);
	}

	/************************* SORT PAIRS BY GREATER VALUE ************************/

	
}


// template class PMergeMe< std::vector >;
// template class PMergeMe< std::deque >;

#endif