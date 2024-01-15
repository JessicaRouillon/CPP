#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:
// Constructors & Destructor
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& copy);
	~Form();

	Form& operator=(const Form& right);

// Getters & Setters
	std::string	getName() const;
	bool		getSignedStatus() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	void		setSignedStatus(bool const status);

// Member functions

	void	beSigned(Bureaucrat& ref);

// Exceptions

	class Exception : public std::exception
	{
		public :
			const char*	what() const throw ();
	};

	class GradeTooHighException : public Form::Exception
	{
		public :
			const char*	what() const throw();
	};

	class GradeTooLowException : public Form::Exception
	{
		public :
			const char*	what() const throw();
	};

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

};

std::ostream&	operator<<(std::ostream& output_stream, Form const &form);

#endif