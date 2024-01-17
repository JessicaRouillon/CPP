#include "ScalarConverter.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

ScalarConverter::ScalarConverter(const std::string string) : _string(string) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) : _string(copy.getString()), _type(copy.getType()) {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	this->_string = src.getString();
	this->_type = src.getType();
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

/*********************************** Getters ************************************/

ScalarConverter&	ScalarConverter::getInstance()
{
	static ScalarConverter	instance;
	return (instance);
}

std::string	ScalarConverter::getString() const { return (this->_string); }

t_type	ScalarConverter::getType() const { return (this->_type); }

void	ScalarConverter::setString(std::string str)
{
	this->_string = str;
}

void	ScalarConverter::setType(std::string str)
{
	this->_type = assignType(str);
}

/**************************** Assign Type Functions *****************************/

t_type	ScalarConverter::assignType(const std::string &str) const
{
	t_type	exception = assignExceptionType(str);

	if (exception != UNKNOWN)
		return (exception);
	if (assignCharType(str) == true)
		return (CHAR);
	if (assignIntType(str) == true)
		return (INT);
	if (assignFloatType(str) == true)
		return (FLOAT);
	if (assignDoubleType(str) == true)
		return (DOUBLE);
	return (UNKNOWN);
}

t_type	ScalarConverter::assignExceptionType(const std::string &str) const
{
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
		return (DOUBLE);
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		return (FLOAT);
	return (UNKNOWN);
}

bool	ScalarConverter::assignCharType(const std::string &str) const
{
	return (str.length() == 1 && !isdigit(str[0]));
}

bool	ScalarConverter::assignIntType(const std::string &str) const
{
	size_t	i = 0;

	if (str.length() <= 1 && (str[0] == '+' || str[0] == '-'))
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i += 1;
	for (; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

bool	ScalarConverter::assignFloatType(const std::string &str) const
{
	size_t i = 0;
	bool decimal = false;

	if (str.length() <= 1 && (str[0] == '+' || str[0] == '-'))
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i += 1;
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == str.length() - 1)
				return (str[i] == 'f');
			if (str[i] == '.' || str[i] == ',')
			{
				if (decimal == true)
					return (false);
				decimal = true;
			}
			else
				return (false);
		}
	}
	return (false);
}

bool	ScalarConverter::assignDoubleType(const std::string &str) const
{
	size_t i = 0;
	bool decimal = false;

	if (str.length() <= 1 && (str[0] == '+' || str[0] == '-'))
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i += 1;
	for (; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
		{
			if (str[i] == '.' || str[i] == ',')
			{
				if (decimal == true)
					return (false);
				decimal = true;
			}
			else
				return (false);
		}
	}
	return (true);
}

/**************************** Conversion Functions *****************************/

static void	convertFromChar(const std::string &str)
{
	char c = str[0];

	if (isprint(c) == false)
		std::cout << "char: Not printable" << std::endl;
	else
	{
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
}

static void	convertFromInt(const std::string &str)
{
	long int value = std::strtol(str.c_str(), NULL, 10);

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "Error: Int overflow error" << std::endl;
		return;
	}
	if (isprint(value) == false)
		std::cout << "char: Not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

static void	convertFromFloat(const std::string &str)
{
	float	value = strtof(str.c_str(), NULL);

	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str.compare("nanf") == 0)
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (str.compare("-inff") == 0)
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else if (str.compare("+inff") == 0)
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		return;
	}
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "Error: Float overflow error" << std::endl;
		return;
	}
	if (isprint(value) == false)
		std::cout << "char: Not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) << std::endl;
}

static void	convertFromDouble(const std::string &str)
{
	double	value = strtod(str.c_str(), NULL);

	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str.compare("nan") == 0)
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (str.compare("-inf") == 0)
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else if (str.compare("+inf") == 0)
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		return;
	}
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "Error: Double overflow error" << std::endl;
		return;
	}
	if (isprint(value) == false)
		std::cout << "char: Not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert()
{
	conversions	functions[] = {convertFromChar, convertFromInt, convertFromFloat, convertFromDouble};

	if (_type == UNKNOWN)
		throw(ScalarConverter::UnknownType());
	else
	{
		functions[_type](_string);
	}
}

/******************************** Exceptions *********************************/

const char*	ScalarConverter::UnknownType::what() const throw()
{
	return ("Error: Unknown type");
}
