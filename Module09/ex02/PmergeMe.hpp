#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <deque>
#include <ctime>

#define RED "\033[0;31m"
#define NC "\033[0m"

// template<typename Container>

class PMergeMe
{

public:

	PMergeMe() {}
	PMergeMe(const PMergeMe &copy) { *this = copy; };
	~PMergeMe(){};

	PMergeMe &operator=(const PMergeMe &src);


	bool	isValidInput(const int ac, const char **av);
	void	sort(const int ac,  const char **av);

private:

	bool						isValidArg(const char *av);
	bool						isOddArgs(const int& ac);
	std::deque<std::deque<int>>	createPairs(const std::vector<int>& vec);

	bool	_isOdd;
	int		_straggler;
};

#endif