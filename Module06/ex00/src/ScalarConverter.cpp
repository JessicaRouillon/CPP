#include "ScalarConverter.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

ScalarConverter::ScalarConverter(const std::string string): _string(string) {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy): _string(copy.getString()), _type(copy.getType()) {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& src)
{
	this->_string = src.getString();
	this->_type = src.getType();
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/


/*********************************** Getters ************************************/

std::string		ScalarConverter::getString() const { return (this->_string); }

t_type		ScalarConverter::getType() const { return (this->_type); }


/**************************** Assign Type Functions *****************************/

t_type		ScalarConverter::assignType(const std::string str) const
{
	t_type	exception = assignExceptionType(str);

	if (exception != UNKNOWN)
		return (i);
	if (assignCharType(str) == true)
		return (CHAR);
	if (assignIntType(str) == true)
		return (INT);
	if (assignFloatType(str) == true)
		return (FLOAT);
	if (assignDoubleType(str) == true)
		return (DOUBLE);
}

t_Type	ScalarConverter::assignException(const std::string str) const
{
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
		return (DOUBLE);
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		return (FLOAT);
	return (UNKNOWN);
}

bool	ScalarConverter::assignCharType(const std::string str) const
{

}


/**************************** Conversion Functions *****************************/

void	ScalarConverter::convert(const std::string& str)
{
	t_type	type = assignType(str);

	if (type == UNKNOWN)
		throw (ScalarConverter::UnknownType());
	else
	{
		ScalarConverter	conversions[4] = { &convertFromChar, &convertFromInt, &convertFromFloat, &convertFromDouble};
		conversions[type](str);
	}
}


/******************************** Exceptions *********************************/

const char*	ScalarConverter::Exception::what() const throw()
{
	return ("Cannot be converted");
}

const char*	ScalarConverter::NotPrintable::what() const throw()
{
	return ("Not printable");
}

const char*	ScalarConverter::UnknownType::what() const throw()
{
	return ("Unknown type");
}
