#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <vector>
#include <deque>
#include <ctime>


#define RED "\033[0;31m"
#define NC "\033[0m"


template <template<typename, typename> class Container>
class PMergeMe
{

public:

	PMergeMe(char **av);
	PMergeMe(const PMergeMe &copy);
	~PMergeMe() {}

	PMergeMe &operator=(const PMergeMe &src);


	void	sort();
	void	printData() const;
	void	printSorted() const;
	void	printTime(const std::string str) const;


private:

	PMergeMe(): _data(), _time(0), _straggler(-1) {}

	// Sort functions
	void	createPairs();
	void	sortPairsByGreaterValues();
	void	createMainChain();
	void	resizePendChain();
	void	mergeInsertSort();
	void	insertStraggler();

	// Utils
	bool	isValidArg(const char *av);
	void	getTime(const clock_t startTime);
	int		binarySearch(const int size, const int n);
	int 	findLowerBound(const std::vector<int> sequence);
	int 	getLowestValue(const int nb, const size_t size);
	const std::vector<int>	buildJacobsthalSequence();

	Container< int, std::allocator<int> >	_data;
	Container< int, std::allocator<int> >	_sorted;
	double	_time;
	int		_straggler;
};

#include "PmergeMe.cpp"

#endif