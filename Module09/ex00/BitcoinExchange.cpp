#include "BitcoinExchange.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

BitcoinExchange::BitcoinExchange(std::string const inputfile)
{
	if (inputfile.empty() == true)
		throw(BitcoinExchange::InvalidNumberArgs());
	try
	{
		_data = setData();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		_output = setOutput(inputfile);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	_data = copy.getData();
	_output = copy.getOutput();
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		_data = src.getData();
		_output = src.getOutput();
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
		delimiter = line.find(',');
		date = line.substr(0, delimiter);
		value = line.substr(delimiter + 1);
		res.insert(std::make_pair(date, value));
	}

	// printData(res);

	/***************************** CLOSE FILE *****************************/

	datafile.close();
	return (res);
}


std::map<std::string, std::string>	BitcoinExchange::setOutput(const std::string& inputfile)
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

	/***************************** SET OUTPUT *****************************/

	size_t			delimiter;
	std::string		date;
	std::string		value;
	size_t i = 0;
	std::map<std::string, std::string>	res;

	while (std::getline(input, line))
	{
		delimiter = line.find('|');
		date = line.substr(0, delimiter - 1);
		std::cout << i << "/" << std::endl;
		value = line.substr(delimiter + 2);
		std::cout << date << ": " << value << std::endl << std::endl;
		res.insert(std::make_pair(date, value));
		printOutput(res);
		std::cout << std::endl;
		i++;
	}

	// printOutput(res);

	/***************************** CLOSE FILE *****************************/

	input.close();
	return (res);
}


void	BitcoinExchange::printData(const std::map<std::string, std::string>& data)
{
	std::cout << "data.csv" << std::endl;
	std::map<std::string, std::string>::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

void	BitcoinExchange::printOutput(const std::map<std::string, std::string>& output)
{
	std::cout << "input.txt" << std::endl;
	std::map<std::string, std::string>::const_iterator it;
	for (it = output.begin(); it != output.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}
