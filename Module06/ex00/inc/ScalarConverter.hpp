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
	t_type			getType(const std::string str) const;

// Conversion Functions
	operator	char();
	operator	int();
	operator	float();
	operator	double();

// Exception
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


private :
	std::string	_string;
	t_type		_type;

};

#endif