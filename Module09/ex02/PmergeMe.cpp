#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include "PmergeMe.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/


template <template <typename, typename> class Container>
PMergeMe<Container>::PMergeMe(char **av) : _time(0)
{
	_straggler = -1;

	for (size_t i = 0; av[i]; ++i)
	{
		if (isValidArg(av[i]) == false)
			throw(std::invalid_argument("\033[0;31mError: Invalid input\033[0m"));
		_data.push_back(atoi(av[i]));
	}
	if ((_data.size() % 2) != 0)
	{
		_straggler = _data.back();
		_data.erase(_data.end() - 1);
	}
}



template <template <typename, typename> class Container>
PMergeMe<Container>::PMergeMe(const PMergeMe<Container> &copy)
{
	_data = copy._data;
	_sorted = copy._sorted;
	_time = copy._time;
	_straggler = copy._straggler;
}



template <template <typename, typename> class Container>
PMergeMe<Container> &PMergeMe<Container>::operator=(const PMergeMe<Container> &src)
{
	if (this != &src)
	{
		_data = src._data;
		_sorted = src._sorted;
		_time = src._time;
		_straggler = src._straggler;
	}
	return (*this);
}



/********************************************************************************/
/******************************* PRINT FUNCTIONS ********************************/
/********************************************************************************/


template <template <typename, typename> class Container>
bool PMergeMe<Container>::isValidArg(const char *av)
{
	const char *base = "0123456789";

	for (size_t i = 0; av[i]; ++i) {
		if (!strchr(base, av[i]))
			return (false);
	}
	return (true);
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::printData() const
{
	for (size_t i = 0; i < _data.size(); ++i)
		std::cout << _data[i] << " ";
	if (_straggler >= 0)
		std::cout << _straggler;
	std::cout << std::endl;
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::printSorted() const
{
	for (size_t i = 0; i < _sorted.size(); ++i)
		std::cout << _sorted[i] << " ";
	if (_straggler >= 0)
		std::cout << _straggler;
	std::cout << std::endl;
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::printTime(const std::string str) const
{
	std::cout << "Time to process a range of " << _sorted.size()
			  << " elements with std::" << str << " : "
			  << std::fixed << std::setprecision(5) << _time << "ms" << std::endl;
}



/********************************************************************************/
/******************************** SORT FUNCTIONS ********************************/
/********************************************************************************/


template <template <typename, typename> class Container>
void PMergeMe<Container>::createPairs()
{
	typename Container<int, std::allocator<int> >::iterator it;

	for (it = _data.begin(); it != _data.end(); it += 2) {
		if (it[0] > it[1])
			std::iter_swap(it, it + 1);
	}
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::sortPairsByGreaterValues()
{
	typename Container<int, std::allocator<int> >::iterator it;
	typename Container<int, std::allocator<int> >::iterator it1;

	for (it = _data.begin(); it < _data.end(); it += 2)
	{
		typename Container<int, std::allocator<int> >::iterator itMin = it;
		for (it1 = it + 2; it1 < _data.end(); it1 += 2) {
			if (itMin[1] > it1[1])
				itMin = it1;
		}
		if (itMin != it1) {
			std::iter_swap(it, itMin);
			std::iter_swap(it + 1, itMin + 1);
		}
	}
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::createMainChain()
{
	typename Container<int, std::allocator<int> >::iterator it;

	/* Begin with first value because we know it is the smallest */
	_sorted.push_back(*_data.begin());

	/* Push greater values into main chain */
	it = _data.begin() + 1;
	for (size_t i = 1; it != _data.end(); ++i, ++it) {
		if (i % 2 != 0)
			_sorted.push_back(*it);
	}
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::resizePendChain()
{
	size_t size = 0;

	for (size_t i = 2; i < _data.size(); i += 2) {
		_data[size++] = _data[i];
	}
	_data.resize(size);
}



template <template <typename, typename> class Container>
int PMergeMe<Container>::binarySearch(const int size, const int n)
{
	int min = 0;
	int max = size;

	while (min <= max) {
		int middle = min + (max - min) / 2;

		if (_sorted[middle] == n)
			return (middle + 1);
		else if (_sorted[middle] < n)
			min = middle + 1;
		else
			max = middle - 1;
	}
	return (min);
}



template <template <typename, typename> class Container>
const std::vector<int> PMergeMe<Container>::buildJacobsthalSequence()
{
	std::vector<int> res;
	int sequence[] = {1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

	for (size_t i = 0; i < (sizeof(sequence) / sizeof(sequence[0])); ++i) {
		res.push_back(sequence[i] * 2);
	}
	return (res);
}



template <template <typename, typename> class Container>
int PMergeMe<Container>::getLowestValue(const int nb, const size_t size)
{
	int result = std::min(nb, static_cast<int>(size));
	return (result);
}



template <template <typename, typename> class Container>
int PMergeMe<Container>::findLowerBound(const std::vector<int> sequence)
{
	std::vector<int>::const_iterator it = std::lower_bound(sequence.begin(), sequence.end(), static_cast<int>(_data.size()));
	int	index = 0;

	if (it != sequence.end()) {
		index = *it;
	}
	return (index);
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::mergeInsertSort()
{
	// binarysearch
	// use jacobsthal to reduce range of search for binarysearch

	const std::vector<int> JacobsthalSequence = buildJacobsthalSequence();
	int JacobIndex = findLowerBound(JacobsthalSequence);
	int i = 0;
	int searchIdx = 2;

	while (JacobsthalSequence[i] <= JacobIndex)
	{
		if (_data.empty() == true) {
			break;
		}

		int maxIdx = getLowestValue(JacobsthalSequence[i], _data.size());
		searchIdx += maxIdx;

		typename Container<int, std::allocator<int> >::reverse_iterator rit;
		for (rit = _data.rend() - maxIdx; rit != _data.rend(); ++rit) {
			int BinaryIdx = binarySearch(searchIdx, *rit);
			_sorted.insert(_sorted.begin() + BinaryIdx, *rit);
			++searchIdx;
		}
		_data.erase(_data.begin(), _data.begin() + maxIdx);
		++i;
	}
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::insertStraggler()
{
	if (_straggler >= 0)
	{
		typename Container<int, std::allocator<int> >::iterator insertionPoint = std::lower_bound(_sorted.begin(), _sorted.end(), _straggler);
		_sorted.insert(insertionPoint, _straggler);
		_straggler = -1;
	}
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::getTime(const clock_t startTime)
{
	clock_t endTime = clock();
	_time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
}



template <template <typename, typename> class Container>
void PMergeMe<Container>::sort()
{
	if (_data.size() <= 1)
		return;

	clock_t startTime = clock();

	createPairs();
	sortPairsByGreaterValues();
	createMainChain();
	resizePendChain();
	mergeInsertSort();
	insertStraggler();
	getTime(startTime);
}


// template class PMergeMe< std::vector >;
// template class PMergeMe< std::deque >;

#endif