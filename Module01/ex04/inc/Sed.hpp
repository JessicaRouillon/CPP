#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <string>
#include <cstdlib> // EXIT_SUCCESS / EXIT_FAILURE
#include <fstream> // opening, reading and writing in files

class Sed
{

public:

	Sed(const std::string &filename, const std::string &s1, const std::string &s2);
	~Sed();

	void			setFilename(const std::string &filename);
	void			setOutputFilename(const std::string &filename);
	void			setStringOne(const std::string &s1);
	void			setStringTwo(const std::string &s2);

	std::string		getInputFile(void) const;
	std::string		getOutputFile(void) const;
	std::string		getStringOne(void) const;
	std::string		getStringTwo(void) const;

	std::string		replaceString(std::string buffer, const std::string s1, const std::string s2);

private:

	std::string		_inputFile;
	std::string		_outputFile;
	std::string		_s1;
	std::string		_s2;
};

#endif