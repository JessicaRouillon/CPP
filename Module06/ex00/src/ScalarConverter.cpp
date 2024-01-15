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

t_type		ScalarConverter::getType(const std::string str) const
{
	t_type	exception = assignException(str);

	if (exception != UNKNOWN)
		return (i);
	
}


// Conversion Functions

ScalarConverter::operator char()
{
	int		toInt = 0;
	char	toChar = 0;

	if (_string.length() == 1)
	{
		try
		{
			toInt = stoi(_string);
			toChar = static_cast<char>(toInt);
		}
		catch(const std::Exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		if (isPrintable(toChar) == true)
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Not printable" << std::endl;
		return ;
	}
	else
	{

	}
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
