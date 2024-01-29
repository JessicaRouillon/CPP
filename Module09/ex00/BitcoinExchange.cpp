#include "BitcoinExchange.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

BitcoinExchange::BitcoinExchange()
{
	try
	{
		_data = setData();
		// _output = setOutput(inputfile);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	_data = copy.getData();
	// _output = copy.getOutput();
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		_data = src.getData();
		// _output = src.getOutput();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Setters

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
		if (isDateValid(date) == false)
			throw(BitcoinExchange::BadDate());

		value = line.substr(delimiter + 1);
		if (isValueValid(value) == false)
			throw(BitcoinExchange::BadValue());

		res.insert(std::make_pair(date, value));
	}

	// printData(res);

	/***************************** CLOSE FILE *****************************/

	datafile.close();
	return (res);
}


std::string		BitcoinExchange::getDataValue(const std::string& date)
{
	std::map<std::string, std::string>::const_iterator it;
	
	it = this->_data.find(date);
	if (it != this->_data.end())
		return ((*it).second);
	else // find closest date before
	{

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

	while (std::getline(input, line))
	{
		if (*line.begin() == '\n')
			throw(BitcoinExchange::BadFileInput());

		delimiter = line.find('|');
		if (delimiter == std::string::npos)
			throw(BitcoinExchange::BadFileInput());

		date = line.substr(0, delimiter - 1);
		if (isDateValid(date) == false)
			throw(BitcoinExchange::BadDate());

		value = line.substr(delimiter + 2);
		if (isValueValid(value) == false)
			throw(BitcoinExchange::BadValue());

		dataValue = getDataValue(date);
	}
}





// std::map<std::string, std::string>	BitcoinExchange::setOutput(const std::string& inputfile)
// {
// 	/***************************** VERIFY FILE *****************************/

// 	std::ifstream	input(inputfile.c_str());
// 	std::string		line;

// 	input.seekg(0, std::ios::end); // seekg moves the pointer to the end of the file
// 	if (input.is_open() == false)
// 		throw (BitcoinExchange::CannotOpenFile());

// 	if (input.tellg() == 0) // Check where file pointer position is
// 		throw (BitcoinExchange::EmptyFile());
// 	else
// 		input.seekg(0, std::ios::beg); // move the pointer back to the start of the file

// 	std::getline(input, line);
	
// 	if (line != "date | value")
// 		throw (BitcoinExchange::WrongFormat());

// 	/***************************** SET OUTPUT *****************************/

// 	size_t			delimiter;
// 	std::string		date;
// 	std::string		value;
// 	std::map<std::string, std::string>	res;

// 	while (std::getline(input, line))
// 	{
// 		if (*line.begin() == '\n')
// 			throw(BitcoinExchange::BadFileInput());

// 		delimiter = line.find('|');
// 		if (delimiter == std::string::npos)
// 			throw(BitcoinExchange::BadFileInput());

// 		date = line.substr(0, delimiter - 1);
// 		if (isDateValid(date) == false)
// 			throw(BitcoinExchange::BadDate());

// 		value = line.substr(delimiter + 2);
// 		if (isValueValid(value) == false)
// 			throw(BitcoinExchange::BadValue());

// 		res.insert(std::make_pair(date, value));
// 	}

// 	printOutput(res);

// 	/***************************** CLOSE FILE *****************************/

// 	input.close();
// 	return (res);
// }



/********************************************************************************/
/***************************** UTILITY FUNCTIONS ********************************/
/********************************************************************************/

void	BitcoinExchange::printData(const std::map<std::string, std::string>& data)
{
	std::cout << "data.csv" << std::endl;
	std::map<std::string, std::string>::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

// void	BitcoinExchange::printOutput(const std::map<std::string, std::string>& output)
// {
// 	std::cout << "input.txt" << std::endl;
// 	std::map<std::string, std::string>::const_iterator it;
// 	for (it = output.begin(); it != output.end(); ++it)
// 	{
// 		std::cout << it->first << ": " << it->second << std::endl;
// 	}
// }

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
