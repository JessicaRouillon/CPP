#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

typedef enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
}	t_type;

class ScalarConverter
{

public:
// Constructors & Destructor
	ScalarConverter() {};
	ScalarConverter(const std::string string);
	ScalarConverter(const ScalarConverter& copy);
	~ScalarConverter() {};

	ScalarConverter& operator=(const ScalarConverter& src);

// Getter
	std::string		getString() const;
	t_type			getType() const;

// Assign Type Functions
	t_type	assignType(const std::string str) const;
	t_type	assignExceptionType(const std::string str) const;
	bool	assignCharType(const std::string str) const;
	bool	assignIntType(const std::string str) const;
	bool	assignFloatType(const std::string str) const;
	bool	assignDoubleType(const std::string str) const;

// Conversion Functions
	void	convert(const std::string& str);
	void	convertFromChar(const std::string& str);
	void	convertFromInt(const std::string& str);
	void	convertFromFloat(const std::string& str);
	void	convertFromDouble(const std::string& str);

// Exceptions
	class Exception : public std::exception
	{
		public :
			const char*	what() const throw();
	};

	class NotPrintable : public std::exception
	{
		public :
			const char*	what() const throw();
	};

	class UnknownType : public std::exception
	{
		public :
			const char*	what() const throw();
	};


private :
	std::string	_string;
	t_type		_type;

};

#endif