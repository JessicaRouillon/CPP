#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

template <typename T>

class Span
{

	public:
		//Constructors & Destructor
		Span();
		Span(const unsigned int n);
		~Span();

		// Assignment operator & Copy
		Span(const Span& copy);
		Span& operator=(const Span& src);

		// Member functions
		void	addNumber(const int n);
		int		shortestSpan();
		int		longestSpan();

		// Exceptions
		class InsufficientStorage : public std::exception
		{
			public :
				const char* what() const throw() {
					return ("\033[0;31mError: Not enough storage to add a number.\n\033[0m");
				}
		};

		class NoSpanFound : public std::exception
		{
			public :
				const char* what() const throw() {
					return ("\033[0;31mError: Cannot find shortest/longest span. Check that you have more than one number in span.\n\033[0m");
				}
		};

	private:
		T*	_array;
		unsigned int	_nb;
};

#endif