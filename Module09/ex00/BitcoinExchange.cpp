#include "BitcoinExchange.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

BitcoinExchange::BitcoinExchange(std::string const inputfile, std::string const datafile) : _inputFile(inputfile)
{
	if (inputfile.empty() == true)
		throw(BitcoinExchange::InvalidNumberArgs());
	_myBitcoins = setMyBitcoins(inputfile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	_inputFile = copy.getInputFile();
	_myBitcoins = copy.getMyBitcoins();
	_rates = copy.getRates();
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		_inputFile = src.getInputFile();
		_myBitcoins = src.getMyBitcoins();
		_rates = src.getRates();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Setters

std::map<std::string, float>	BitcoinExchange::setMyBitcoins(std::string const& inputfile)
{
	std::ifstream		input(this->getInputFile().c_str());

	input.seekg(0, std::ios::end);					   // seekg moves the pointer to the end of the file
	if (input.is_open() == true && input.tellg() != 0) // Check if file can be opened and where file pointer position is
	{
		input.seekg(0, std::ios::beg); // move the pointer back to the start of the file
		
	}
}
