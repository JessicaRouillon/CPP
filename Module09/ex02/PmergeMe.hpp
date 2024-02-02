#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
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
	void	sort();


private:

	PMergeMe(): _data(), _time(0), _straggler(-1) {}


	Container< int, std::allocator<int> >	_data;
	Container< int, std::allocator<int> >	_sorted;
	double	_time; // double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	int		_straggler;
};

#include "PmergeMe.cpp"

#endif