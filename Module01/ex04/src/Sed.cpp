#include "Sed.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2)
{
	this->setFilename(filename);
	this->setOutputFilename(filename);
	this->setStringOne(s1);
	this->setStringTwo(s2);
}

Sed::~Sed()
{
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Setters

void	Sed::setFilename(const std::string &filename)
{
	_inputFile = filename;
}

void	Sed::setOutputFilename(const std::string &filename)
{
	_outputFile = filename + ".replace";
}

void	Sed::setStringOne(const std::string &s1)
{
	_s1 = s1;
}

void	Sed::setStringTwo(const std::string &s2)
{
	_s2 = s2;
}


// Getters

std::string		Sed::getInputFile(void) const
{
	return (this->_inputFile);
}

std::string		Sed::getOutputFile(void) const
{
	return (this->_outputFile);
}


std::string		Sed::getStringOne(void) const
{
	return (this->_s1);
}

std::string		Sed::getStringTwo(void) const
{
	return (this->_s2);
}


// Member functions

std::string		Sed::replaceString(std::string buffer, const std::string s1, const std::string s2)
{
	size_t	pos = 0;

	pos = buffer.find(s1);
	while (pos != std::string::npos)
	while ((pos = buffer.find(s1, pos + s2.length())) != std::string::npos)
	{
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
	}
	return (buffer);
}
