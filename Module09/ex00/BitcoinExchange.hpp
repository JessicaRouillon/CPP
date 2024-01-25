#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream> // ifstream, ofstream
#include <string> // getline
#include <map>

# define DATA	"data.csv"
# define RED	"\033[0;31m"
# define NC		"\033[0m"

class BitcoinExchange
{

public:
	// Orthodox Canonical Form
	BitcoinExchange(std::string const inputfile, std::string const datafile);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange(){};

	BitcoinExchange &operator=(const BitcoinExchange &src);

	// Setters
	std::map<std::string, float>	setMyBitcoins(std::string const& inputfile);

	// Getters
	std::string						getInputFile() const { return (_inputFile); }
	std::map<std::string, float>	getMyBitcoins() const { return (_myBitcoins); }
	// std::map<std::string, float>	getRates() const { return (_rates); }

	// Exceptions
	class InvalidNumberArgs : public std::exception
	{
		public:
			const char*	what() const throw() { return ("\033[0;31mError: Invalid number of arguments.\033[0m"); }
	};

private:
	std::string 					_inputFile;
	std::map<std::string, float>	_myBitcoins;
	std::string						_output;
	// std::map<std::string, float>	_rates;
};

#endif