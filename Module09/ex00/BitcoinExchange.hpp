#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib> // exit_success/failure
# include <sstream> // ifstream, ofstream
# include <map>

# define RED	"\033[0;31m"
# define NC		"\033[0m"

class BitcoinExchange
{

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& src);

	// Member functions
	std::string		getInputfile(std::string &name);

private:
	std::string		_inputFile;
};

#endif