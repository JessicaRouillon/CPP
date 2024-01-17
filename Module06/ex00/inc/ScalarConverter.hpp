#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype> // isprint
# include <limits> // int min, int max
# include <cstdlib> // strtol, strtof, strtod
# include <cmath> // modf
# include <iomanip> // precision

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
	ScalarConverter(const ScalarConverter& copy);
	~ScalarConverter() {};

	ScalarConverter& operator=(const ScalarConverter& src);

// Getter & Setters
	static ScalarConverter&		getInstance();
	std::string					getString() const;
	t_type						getType() const;
	void						setString(std::string str);
	void						setType(std::string str);

// Assign Type Functions
	t_type	assignType(const std::string& str) const;
	t_type	assignExceptionType(const std::string& str) const;
	bool	assignCharType(const std::string& str) const;
	bool	assignIntType(const std::string& str) const;
	bool	assignFloatType(const std::string& str) const;
	bool	assignDoubleType(const std::string& str) const;

// Conversion Functions
	typedef	void (*conversions)(const std::string& str);
	void	convert();

// Exceptions
	class UnknownType : public std::exception
	{
		public :
			const char*	what() const throw();
	};


private :
	ScalarConverter() {};
	ScalarConverter(const std::string string);
	std::string	_string;
	t_type		_type;

};

#endif