#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{

public:
	Form();
	~Form();

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

};

#endif