#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib> // atoi
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
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange(){};

	BitcoinExchange &operator=(const BitcoinExchange &src);

	// Setters
	std::map<std::string, std::string>	setData();
	// std::map<std::string, std::string>	setOutput(const std::string& inputfile);

	// Getters
	std::map<std::string, std::string>	getData() const { return (_data); }
	std::string							getDataValue(const std::string& date);
	// std::map<std::string, std::string>	getOutput() const { return (_output); }

	void	execute(const std::string& inputfile);

private:
	std::map<std::string, std::string>	_data;
	std::map<std::string, std::string>	_output;

	// Utility Functions
	void		printData(const std::map<std::string, std::string>& data);
	// void		printOutput(const std::map<std::string, std::string>& output);
	bool		isDateValid(const std::string& date);
	bool		isValueValid(const std::string& value);

	// Exceptions
	class CannotOpenFile : public std::exception {
		const char*	what() const throw() { return ("\033[0;31mError: File could not be opened.\033[0m"); } };

	class EmptyFile : public std::exception {
		const char*	what() const throw() { return ("\033[0;31mError: File is empty.\033[0m"); } };

	class WrongFormat : public std::exception {
		const char*	what() const throw() { return ("\033[0;31mError: File format is wrong.\033[0m"); } };

	class CannotCloseFile : public std::exception {
		const char*	what() const throw() { return ("\033[0;31mError: File could not be closed.\033[0m"); } };

	class BadFileInput : public std::exception {
		const char*	what() const throw() { return ("\033[0;31mError: Bad file input.\033[0m"); } };

	class BadDate : public std::exception {
		const char*	what() const throw() { return ("\033[0;31mError: Invalid date in file.\033[0m"); } };

	class BadValue : public std::exception {
		const char*	what() const throw() { return ("\033[0;31mError: Invalid value in file.\033[0m"); } };
};

#endif