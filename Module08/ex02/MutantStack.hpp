#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <vector>

template <typename T>

class MutantStack : public std::stack<T>
{

	public:
		// Orthodox Canonical Form
		MutantStack() {}
		MutantStack(const MutantStack& copy) { *this = copy; }
		~MutantStack() {}

		MutantStack& operator=(const MutantStack& src) {
			this = &src;
			return *this;
		}

		// Iterators
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	constIterator;

		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }
		constIterator	begin() const { return this->c.begin(); }
		constIterator	end() const { return this->c.end(); }
};

#endif
