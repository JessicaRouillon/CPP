#include "Span.hpp"

/********************************************************************************/
/************************** COPY & ASSIGNMENT OPERATOR **************************/
/********************************************************************************/

Span	&Span::operator=(const Span& src)
{
	if (this != &src)
	{
		_nb = src._nb;
		_array = src._array;
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Span::addNumber(const int n)
{
	if (_array.size() >= _nb)
		throw (Span::InsufficientStorage());
	else
		_array.push_back(n);
}

size_t	Span::getSpan(const size_t nb1, const size_t nb2)
{
	if (nb1 - nb2 < 0)
		return (nb2 - nb1);
	return (nb1 - nb2);
}

size_t	Span::shortestSpan()
{
	if (_array.size() < 2)
	throw (Span::NoSpanFound());

	size_t	shortest = std::numeric_limits<unsigned long>::max();
	for (size_t i = 1; i < _array.size(); i++)
	{
		std::cout << "array[i] = " << _array[i] << std::endl;
		std::cout << "array[i - 1] = " << _array[i - 1] << std::endl;
		size_t	span = getSpan(_array[i], _array[i - 1]);
		std::cout << "span = " << span << std::endl << std::endl;
		if (shortest < span)
			shortest = span;
	}
	return (shortest);
}

size_t	Span::longestSpan()
{
	if (_array.size() < 2)
		throw (Span::NoSpanFound());

	size_t	longest = std::numeric_limits<unsigned long>::min();
	size_t	span;

	for (size_t i = 1; i < _array.size(); i++)
	{
		span = _array[i] - _array[i - 1];
		if (span > longest)
			longest = span;
	}
	return (longest);
}
