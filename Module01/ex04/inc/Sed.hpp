#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <cstdlib>

class Sed
{

public:
	Sed();
	~Sed();

private:

	std::string		_filename;
	std::string		_s1;
	std::string		_s2;
};

#endif