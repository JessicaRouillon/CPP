#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <cstdlib>

class Sed
{

public:

	Sed();
	~Sed();

	void			setFilename(std::string filename);
	void			setStringOne(std::string s1);
	void			setStringTwo(std::string s2);

	std::string		getFilename(void) const;
	std::string		getStringOne(void) const;
	std::string		getStringTwo(void) const;

private:

	std::string		_filename;
	std::string		_s1;
	std::string		_s2;
};

#endif