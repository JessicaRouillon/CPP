#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

class MutantStack : public std::stack<>
{

	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		~MutantStack();

		MutantStack& operator=(const MutantStack& src);
};

#endif