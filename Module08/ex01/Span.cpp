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
	_array.push_back(n);
}

void	Span::addManyNumbers()
{
	if (_array.size() >= _nb)
		throw (Span::InsufficientStorage());
	try
	{
		for (size_t i = 0; i < this->getNumber(); i++)
		{
			long randValue = static_cast<long>(std::rand());
			_array.push_back(randValue);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

size_t	Span::getSpan(const long nb1, const long nb2)
{
	if (nb1 > nb2)
		return (nb1 - nb2);
	else
		return (nb2 - nb1);
}

size_t	Span::shortestSpan()
{
	if (_array.size() < 2)
	throw (Span::NoSpanFound());

	size_t	shortest = std::numeric_limits<unsigned long>::max();
	for (size_t i = 1; i < _array.size(); i++)
	{
		for (size_t	k = 0; k < _array.size() - 1; k++)
		{
			size_t	span = getSpan(_array[i], _array[k]);
			if (shortest > span && span != 0)
				shortest = span;
		}
		
	}
	return (shortest);
}

size_t	Span::longestSpan()
{
	if (_array.size() < 2)
		throw (Span::NoSpanFound());

	size_t	longest = std::numeric_limits<unsigned long>::min();
	for (size_t i = 1; i < _array.size(); i++)
	{
		for (size_t	k = 0; k < _array.size() - 1; k++)
		{
			size_t	span = getSpan(_array[i], _array[k]);
		if (span > longest && span != 0)
			longest = span;
		}
	}
	return (longest);
}
