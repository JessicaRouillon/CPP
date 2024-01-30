#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

# define RED	"\033[0;31m"
# define NC		"\033[0m"

class PMergeMe
{

public:
	PMergeMe();
	PMergeMe(const PMergeMe& copy);
	~PMergeMe();

	PMergeMe& operator=(const PMergeMe& src);

private:

};

#endif