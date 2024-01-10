#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

public:
// Constructors & Destructor
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& copy);
	virtual ~AForm();

	AForm& operator=(const AForm& right);

// Getters & Setters
	std::string	getName() const;
	bool		getSignedStatus() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	void		setSignedStatus(bool const status);

// Member functions
	void			beSigned(Bureaucrat& ref);
	virtual void	execute(Bureaucrat const & executor) const = 0;

// Exceptions
	class Exception : public std::exception
	{
		public :
			const char*	what() const throw ();
	};

	class GradeTooHighException : public AForm::Exception
	{
		public :
			const char*	what() const throw();
	};

	class GradeTooLowException : public AForm::Exception
	{
		public :
			const char*	what() const throw();
	};

	class UnsignedException : public AForm::Exception
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

std::ostream&	operator<<(std::ostream& output_stream, AForm const &form);

#endif