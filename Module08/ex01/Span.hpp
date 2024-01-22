#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

template <typename T>

class Span
{

	public:
		//Constructors & Destructor
		Span():_array(new T[0]), _nb(0) {}
		Span(const unsigned int n): _array(new T[n]), _nb(n) {}
		~Span() { delete[] _array; }

		// Assignment operator & Copy
		Span(const Span& copy): _array(new T[copy.size()]) {
			for (size_t i =0; i < copy,size(); i++)
				_array[i] = copy._array[i];
		}
		Span& operator=(const Span& src) {
			if (this != &src)
			{
				delete[] _array;
				_array = new T[src.size()];
				_nb = src.size();
				for (unsigned int i = 0; i < _nb; ++i)
					_array[i] = src[i];
			}
			return (*this);
		}

		// Member functions
		void	Span::addNumber(const int n) {
			for (std::list<int>::iterator it = it.begin(); it != it.end(); it++)
			{
				if (*it == NULL)
				{
					*it = n;
					std::cout << "\033[0;32m" << n << " has been added to the array." << "\033[0m" << std::endl;
					return ;
				}
			}
			throw (Span::InsufficientStorage());
		}

		int		shortestSpan() {
			for (std::list<int>::iterator it = it.begin(); it != it.end(); it++)
			{
				
			}
		}

		int		longestSpan() {
			
		}

		// Exceptions
		class InsufficientStorage : public std::exception
		{
			public :
				const char* what() const throw() {
					return ("\033[0;31mError: Not enough storage to add a number.\n\033[0m");
				}
		}

		class NoSpanFound : public std::exception
		{
			public :
				const char* what() const throw() {
					return ("\033[0;31mError: Cannot find shortest/longest span. Check that you have more than one number in span.\n\033[0m");
				}
		}

	private:
		T*				_array;
		unsigned int	_nb;
};

#endif