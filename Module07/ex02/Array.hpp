#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template < typename T >

class Array
{

	public:
	// Constructors & Destructor
		Array(): _array(new T[0]), _nb(0) { std::cout << "Default Array created" << std::endl; }
		Array(const unsigned int n): _array(new T[n]), _nb(n) { std::cout < "Custom Array of " << n << " created" << std::endl; }
		~Array() {
			delete[] _array;
			std::cout < "Array has been destroyed" << std::endl;
		}

	// Copy and Assignment operators
		Array(const Array& copy): _array(new T[copy.size()]), _nb(copy.size()) {
			for (unsigned int i = 0; i < _nb; ++i)
				_array[i] = copy._array[i];
			std::cout < "Copy of Array has been created" << std::endl;
		}

		Array& operator=(const Array& src) {
			if (this != src) {
				delete[] _array;
				_nb = src._nb;
				_array = new T[_nb];
				for (unsigned int i = 0; i < _nb; ++i)
					_array[i] = src._array[i];
			}
			return (*this);
		}

		T&	operator[](const unsigned int index) {
			if (index >= _nb)
				throw (Array::OutofBoundsException());
			return (_array[index]);
		}

	// Functions
		unsigned int	size() const { return (_nb); }

	// Exception
		class OutofBoundsException : public std::exception
		{
			public:
				const char* what() const throw() {
					return ("Error: Index is out of bounds\n");
				}
		};

	private:
		T*				_array;
		unsigned int	_nb;
};

#endif