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
	
	std::vector<long>	sortedArray = _array;
	std::sort(sortedArray.begin(), sortedArray.end());

	size_t	shortest = std::numeric_limits<unsigned long>::max();
	for (size_t i = 1; i < sortedArray.size(); i++)
	{
		size_t	current = sortedArray[i] - sortedArray[i - 1];
		if (current < shortest)
			shortest = current;
	}
	return (shortest);
}

size_t	Span::longestSpan()
{
	if (_array.size() < 2)
		throw (Span::NoSpanFound());
	
	std::vector<long>	sortedArray = _array;
	
	std::sort(sortedArray.begin(), sortedArray.end());

	return (static_cast<size_t>(sortedArray.back() - sortedArray.front()));
}
