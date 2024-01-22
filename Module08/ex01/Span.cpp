#include "Span.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Span::Span():_array(new T[0]), _nb(0) {}

Span::Span(const unsigned int n): _array(new T[n]), _nb(n) {}

Span::Span(const Span& copy): _array(new T[copy.size()]) 
{
	for (size_t i = 0; i < copy.size(); i++)
		_array[i] = copy._array[i];
}

Span::~Span() { delete[] _array; }

Span	&Span::operator=(const Span& src)
{
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

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Span::addNumber(const int n)
{
	if (_array.size() >= _n)
		throw (Span::InsufficientStorage());
	else
		_array.push_back(n);
}

int		Span::shortestSpan()
{
	if (_array.size() < 2)
		throw (Span::NoSpanFound());
	else
	{
		sort(_array.begin(), _array.end());
		return (_array[1] - _array[0]);
	}
}

int		Span::longestSpan()
{
	if (_array.size() < 2)
		throw (Span::NoSpanFound());
	else
	{
		sort(_array.begin(), _array.end());
		return (_array[_array.size() - 1] - _array[0]);
	}
}
