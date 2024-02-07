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


	bool	isValidArg(const char *av);
	void	printData() const;
	void	printSorted() const;
	void	printTime(const std::string str) const;
	void	sort();
	int		jacobsthal(const int n);
	const Container< int, std::allocator<int> >	buildJacobsthalSequence();


private:

	PMergeMe(): _data(), _time(0), _straggler(-1) {}

	void	addMissingValue(const int i);
	void	isCompleteSequence();
	bool	isSorted();

	Container< int, std::allocator<int> >	_data;
	Container< int, std::allocator<int> >	_sorted;
	double	_time;
	int		_straggler;
};

#include "PmergeMe.cpp"

#endif