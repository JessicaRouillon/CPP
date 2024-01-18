#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

class Array
{

public:
	Array();
	Array(const unsigned int n);
	Array(const Array& copy) {*this = copy; }
	~Array();

	Array& operator=(const Array& src) { (void)src; return (*this);}

private:

};

#endif