#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
	PMergeMe(){};
	PMergeMe(const PMergeMe &copy) { *this = copy; };
	~PMergeMe(){};

	PMergeMe &operator=(const PMergeMe &src)
	{
		if (this != &src)
			*this = src;
		return (*this);
	};

	bool isValidInput(const int ac, const char **av);

private:

	bool	isValidArg(const char *av);
};

#endif