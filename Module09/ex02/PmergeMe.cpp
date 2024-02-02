#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include "PmergeMe.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/


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
	if (_data.size() <= 1)
		return ;

	// clock_t	startTime = clock();

	/******************************** CREATE PAIRS ********************************/

	typename	Container< int, std::allocator<int> >::iterator	it;

	for (it = _data.begin(); it != _data.end(); it += 2)
	{
		if (it[0] > it[1])
			std::iter_swap(it, it + 1);
	}

	/************************* SORT PAIRS BY GREATER VALUE ************************/

	typename	Container< int, std::allocator<int> >::iterator		it1;

	for (it = _data.begin(); it < _data.end(); it += 2)
	{
		typename	Container< int, std::allocator<int> >::iterator	itMin = it;
		for (it1 = it + 2; it1 < _data.end(); it1 += 2)
		{
			if (itMin[1] > it1[1])
				itMin = it1;
		}
		if (itMin != it1)
		{
			std::iter_swap(it, itMin);
			std::iter_swap(it + 1, itMin + 1);
		}
	}

	/*********************** CREATE 'S' SEQUENCE (_sorted) ***********************/
	

	/* Begin with first value because we know it is the smallest */
	_sorted.push_back(_data.begin());


	/* Push greater values into 'S' sequence */
	for (it = _data.begin() + 1; size_t i = 1;  it != _data.end(); i++, it++)
	{
		if (i % 2 != 0)
			_sorted.push_back(*it);
	}

}


// template class PMergeMe< std::vector >;
// template class PMergeMe< std::deque >;

#endif