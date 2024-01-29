#include "BitcoinExchange.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

BitcoinExchange::BitcoinExchange()
{
	try
	{
		_data = setData();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	_data = copy.getData();
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		_data = src.getData();
	return (*this);
}


/********************************************************************************/
/***************************** UTILITY FUNCTIONS ********************************/
/********************************************************************************/


static bool		isLeapYear(const int& year)
{
	int		base;

	for (base = 2012; base <= 2024; base += 4)
	{
		if (year == base)
			return (true);
	}
	return (false);
}



static bool		ft_isDigit(const std::string& str, const int type)
{
	std::string::const_iterator	it;

	if (type == 0)
	{
		for (it = str.begin(); it < str.end(); it++)
		{
			if (isdigit(*it) == false)
				return (false);
		}
	}
	else if (type == 1)
	{
		int		flag = 0;
		it = str.begin();

		if (*it == '-' || *it == '+')
			it++;
		for (; it < str.end(); it++)
		{
			if (isdigit(*it) == false && *it != '-' && *it != '+' && *it != '.')
				return (false);
			if (*it == '-' || *it == '+')
				return (false);
			if (isdigit(*it) == false && flag == 1)
				return (false);
			else if (isdigit(*it) == false && *it == '.' && flag == 0)
				flag = 1;
		}
	}
	return (true);
}



bool	BitcoinExchange::isDateValid(const std::string& date)
{
	if (date.length() != 10)
		return (false);
	
	if (date[4] != '-' || date[7] != '-')
		return (false);
	
	std::string	year = date.substr(0, 4);
	std::string	month = date.substr(5, 2);
	std::string	day = date.substr(8, 2);

	if (ft_isDigit(year, 0) == false || ft_isDigit(month, 0) == false || ft_isDigit(day, 0) == false)
		return (false);

	int 	intYear = atoi(year.c_str());
	int 	intMonth = atoi(month.c_str());
	int 	intDay = atoi(day.c_str());

	if (intYear < 2009 || intYear > 2024)
		return (false);
	if (intMonth < 1 || intMonth > 12)
		return (false);
	if (intDay < 1 || intDay > 31)
		return (false);

	if ((intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) && intDay > 30 )
		return (false);
	if (intMonth == 2 && isLeapYear(intYear) == true && intDay > 29)
		return (false);
	if (intMonth == 2 && isLeapYear(intYear) == false && intDay > 28)
		return (false);

	return (true);
}



bool	BitcoinExchange::isValueValid(const std::string& value)
{
	if (ft_isDigit(value, 1) == false)
		return (false);
	return (true);
}



/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/




std::map<std::string, std::string>	BitcoinExchange::setData()
{
	/***************************** VERIFY FILE *****************************/

	std::ifstream	datafile(DATA);
	std::string		line;

	datafile.seekg(0, std::ios::end); // seekg moves the pointer to the end of the file
	if (datafile.is_open() == false)
		throw (BitcoinExchange::CannotOpenFile());

	if (datafile.tellg() == 0) // Check where file pointer position is
		throw (BitcoinExchange::EmptyFile());
	else
		datafile.seekg(0, std::ios::beg); // move the pointer back to the start of the file

	std::getline(datafile, line);

	if (line != "date,exchange_rate")
		throw (BitcoinExchange::WrongFormat());

	/***************************** SET DATA *****************************/

	size_t			delimiter;
	std::string		date;
	std::string		value;
	std::map<std::string, std::string>	res;

	while (std::getline(datafile, line))
	{
		if (*line.begin() == '\n')
			throw(BitcoinExchange::BadFileInput());

		delimiter = line.find(',');
		if (delimiter == std::string::npos)
			throw(BitcoinExchange::BadFileInput());

		date = line.substr(0, delimiter);
		if (date.empty() || isDateValid(date) == false)
			throw(BitcoinExchange::BadDate());

		value = line.substr(delimiter + 1);
		if (value.empty() || isValueValid(value) == false)
			throw(BitcoinExchange::BadValue());

		res.insert(std::make_pair(date, value));
	}

	/***************************** CLOSE FILE *****************************/

	datafile.close();
	return (res);
}



std::string		BitcoinExchange::findPreviousDate(const std::string& date)
{
	std::string	year = date.substr(0, 4);
	std::string	month = date.substr(5, 2);
	std::string	day = date.substr(8, 2);

	int 	intYear = atoi(year.c_str());
	int 	intMonth = atoi(month.c_str());
	int 	intDay = atoi(day.c_str());

	int		daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	intDay -= 1;
	if (intDay == 0)
	{
		intMonth -= 1;
		if (intMonth == 0)
		{
			intMonth = 12;
			intYear--;
		}
		if (isLeapYear(intYear) == true)
			intDay = 29;
		else
			intDay = daysInMonths[intMonth - 1];
	}

	std::ostringstream ossDay;
	std::ostringstream ossMonth;
	std::ostringstream ossYear;

	ossDay << intDay;
	ossMonth << intMonth;
	ossYear << intYear;

	std::string	prevDay = (intDay < 10) ? "0" + ossDay.str(): ossDay.str();
	std::string	prevMonth = (intMonth < 10) ? "0" + ossMonth.str(): ossMonth.str();
	std::string	prevYear = ossYear.str();

	return (prevYear + "-" + prevMonth + "-" + prevDay);
}



std::string		BitcoinExchange::getDataValue(const std::string& date)
{
	std::map<std::string, std::string>::const_iterator it;
	std::string		res;

	it = this->_data.find(date);
	if (it != this->_data.end())
	{
		return ((*it).second);
	}
	else
	{
		std::string	prevDate = this->findPreviousDate(date);
		res = getDataValue(prevDate);
		return (res);
	}
}



void	BitcoinExchange::execute(const std::string& inputfile)
{
	/***************************** VERIFY FILE *****************************/

	std::ifstream	input(inputfile.c_str());
	std::string		line;

	input.seekg(0, std::ios::end); // seekg moves the pointer to the end of the file
	if (input.is_open() == false)
		throw (BitcoinExchange::CannotOpenFile());

	if (input.tellg() == 0) // Check where file pointer position is
		throw (BitcoinExchange::EmptyFile());
	else
		input.seekg(0, std::ios::beg); // move the pointer back to the start of the file

	std::getline(input, line);
	
	if (line != "date | value")
		throw (BitcoinExchange::WrongFormat());

	/***************************** EXECUTE *****************************/

	size_t			delimiter;
	std::string		date;
	std::string		value;
	std::string		dataValue;
	double			final;

	std::cout << "DATE       | VALUE" << std::endl;
	std::cout << "----------------------------" << std::endl;
	while (std::getline(input, line))
	{
		if (*line.begin() == '\n')
		{
			std::cout << RED << "Error: Newline" << NC << std::endl;
			continue;
		}

		delimiter = line.find('|');
		if (delimiter == std::string::npos)
		{
			std::cout << RED << "Error: No separator" << NC << std::endl;
			continue;
		}

		date = line.substr(0, delimiter - 1);
		if (isDateValid(date) == false)
		{
			std::cout << RED << "Error: Bad input => " << date << NC << std::endl;
			continue;
		}

		value = line.substr(delimiter + 1);
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		if (value.empty() || isValueValid(value) == false)
		{
			std::cout << RED << "Error: Bad value input" << NC << std::endl;
			continue;
		}

		dataValue = getDataValue(date);
		final = strtod(dataValue.c_str(), NULL) * strtod(value.c_str(), NULL);
		if (final < 0)
			std::cout << RED << "Error: Not a positive number" << NC << std::endl;
		else if (final > std::numeric_limits<int>::max())
			std::cout << RED << "Error: Number too big" << NC << std::endl;
		else
		{
			std::cout << line << " * " << dataValue << " = ";
			std::cout << std::fixed << std::setprecision(2)	<< final << std::endl;
		}
	}
	input.close();
}
