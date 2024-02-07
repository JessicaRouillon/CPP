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
void	PMergeMe<Container>::addMissingValue(const int i)
{
	int item = _data[i - 1];
	typename	Container< int, std::allocator<int> >::iterator	insertionPoint = std::lower_bound(_sorted.begin(), _sorted.end(), item);
		_sorted.insert(insertionPoint, item);
}



template <template<typename, typename> class Container>
static bool	isInSequence(const int nb, Container< int, std::allocator<int> > sorted)
{
	for(size_t i = 0; i < sorted.size(); i++)
	{
		if (nb == sorted[i])
			return (true);
	}
	return (false);
}


template <template<typename, typename> class Container>
void	PMergeMe<Container>::isCompleteSequence()
{
	for(size_t i = 0; i < _data.size(); i++)
	{
		std::cout << _data[i] << std::endl;
		if (isInSequence(_data[i], _sorted) == false)
			this->addMissingValue(i);
	}
}



template <template<typename, typename> class Container>
bool	PMergeMe<Container>::isSorted()
{
	for(size_t i = 1; i < _sorted.size(); i++)
	{
		if (_sorted[i] < _sorted[i - 1])
			return (false);
	}
	return (true);
}


/********************************************************************************/
/************************* PUBLIC MEMBER FUNCTIONS ******************************/
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



// Print functions

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
void	PMergeMe<Container>::printSorted() const
{
	for(size_t i = 0; i < _sorted.size(); i++)
		std::cout << _sorted[i] << " ";
	if (_straggler >= 0)
		std::cout << _straggler;
	std::cout << std::endl;
}




template <template<typename, typename> class Container>
void	PMergeMe<Container>::printTime(const std::string str) const
{
	std::cout << "Time to process a range of " << _sorted.size()
			<< " elements with std::" << str << " : "
			<< std::fixed << std::setprecision(5) << _time << std::endl;
}




// Sort functions

template <template<typename, typename> class Container>
int	PMergeMe<Container>::jacobsthal(const int n)
{
	if (n == 0)	return (0);
	if (n == 1)	return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}




template <template<typename, typename> class Container>
const Container< int, std::allocator<int> >	PMergeMe<Container>::buildJacobsthalSequence()
{
	Container< int, std::allocator<int> >	seq;
	int		size =_data.size();
	int		jacobIndex = 3; // The first one that matters

	while (jacobsthal(jacobIndex) < size - 1) {
		seq.push_back(jacobsthal(jacobIndex));
		++jacobIndex;
	}
	return (seq);
}




template <template<typename, typename> class Container>
void	PMergeMe<Container>::sort()
{
	if (_data.size() <= 1)
		return ;

	clock_t	startTime = clock();

	/******************************** CREATE PAIRS ********************************/

	typename	Container< int, std::allocator<int> >::iterator	it;

	for (it = _data.begin(); it != _data.end(); it += 2)
	{
		if (it[0] > it[1])
			std::iter_swap(it, it + 1);
	}

	std::cout << "After pair creation" << std::endl;
	printData();
	std::cout << std::endl;

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

	std::cout << "After sort pair by greater values" << std::endl;
	printData();
	std::cout << std::endl;



	/*********************** CREATE 'S' SEQUENCE (_sorted) ***********************/


	/* Begin with first value because we know it is the smallest */
	_sorted.push_back(*_data.begin());


	/* Push greater values into 'S' sequence */
	it = _data.begin();
	for (size_t i = 2;  it != _data.end(); i++, it++)
	{
		if (i % 2 != 0)
			_sorted.push_back(*it);
	}


	/* Keep only small values in _data */
	size_t size = 0;
	for (size_t i = 2; i < _data.size(); i += 2) {
		_data[size++] = _data[i];
	}
	_data.resize(size);

	std::cout << "After S sequence creation" << std::endl;
	std::cout << "data = ";
	printData();
	std::cout << "sorted = ";
	printSorted();
	std::cout << std::endl;



	/***************** BUILD INSERTION SEQUENCE USING JACOBSTHAL *****************/

	Container< int, std::allocator<int> >	JacobsthalSequence = buildJacobsthalSequence();
	Container< int, std::allocator<int> >	indexSequence(1, 1); // Index sequence for reporting purposes

	size_t	iterator = 1; // Already added one
	bool	last = false;
	int		item;

	// Build the valid Jacobsthal sequence, then we can fill in the rest
	while (iterator <= _data.size())
	{
		if (JacobsthalSequence.size() != 0 && last == false) // Use Jacobsthal index if it is valid
		{
			indexSequence.push_back(JacobsthalSequence[0]);
			item = _data[JacobsthalSequence[0] - 1];
			std::cout << "item = " << item << std::endl;

			JacobsthalSequence.erase(JacobsthalSequence.begin());
			last = true;
		}
		else
		{
			// std::cout << "iterator = " << iterator << std::endl;
			// std::cout << "indexSequence begin = " << indexSequence.begin() << std::endl;
			// std::cout << "indexSequence end = " << indexSequence.end() << std::endl;
			if (std::find(indexSequence.begin(), indexSequence.end(), iterator) != indexSequence.end())
				iterator++;
			item = _data[iterator - 1];
			indexSequence.push_back(iterator);
			last = false;
		}

		typename	Container< int, std::allocator<int> >::iterator	insertionPoint = std::lower_bound(_sorted.begin(), _sorted.end(), item);
		_sorted.insert(insertionPoint, item);

		std::cout << "===============================\n" << "After insert" << std::endl;
		std::cout << "data = ";
		printData();
		std::cout << "sorted = ";
		printSorted();
		std::cout << std::endl;

		iterator++;
	}


	if (_straggler >= 0)
	{
		typename	Container< int, std::allocator<int> >::iterator	insertionPoint = std::lower_bound(_sorted.begin(), _sorted.end(), _straggler);
		_sorted.insert(insertionPoint, _straggler);
		_straggler = -1;
	}


	/*************************** CHECKING 'S' SEQUENCE ***************************/

	// isCompleteSequence();
	// if (this->isSorted() == false)
	// 	this->sort();


	/********************************* GET TIME **********************************/

	clock_t	endTime = clock();
	_time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

}


// template class PMergeMe< std::vector >;
// template class PMergeMe< std::deque >;

#endif