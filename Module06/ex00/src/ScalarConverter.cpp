#include "ScalarConverter.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

ScalarConverter::ScalarConverter(const std::string string): _string(string) {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy): _string(copy.getString()) {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& src)
{
	this->_string = src.getString();
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getter

std::string		ScalarConverter::getString() const
{
	return (this->_string);
}


// Conversion Functions

ScalarConverter::operator char()
{

}


// Other functions

bool	isPrintable(char c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}

// Exception

const char*	ScalarConverter::Exception::what() const throw()
{
	return ("Cannot be converted");
}

const char*	ScalarConverter::NotPrintable::what() const throw()
{
	return ("Not printable");
}
