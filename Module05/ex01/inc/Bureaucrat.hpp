#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:
// Constructors & Destructor
	Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& src);

// Getters
	std::string		getName() const;
	int				getGrade() const;

// Increment & Decrement
	void			incrementGrade();
	void			decrementGrade();

// Member functions
	void			signForm(const Form& form) const;

// Exceptions
	class Exception : public std::exception
	{
		public :
			const char*		what() const throw();
	};

	class GradeTooHighException : public Bureaucrat::Exception
	{
		public :
			const char*		what() const throw();
	};

	class GradeTooLowException : public Bureaucrat::Exception
	{
		public :
			const char*		what() const throw();
	};

	class InvalidName : public Bureaucrat::Exception
	{
		public :
			const char*		what() const throw();
	};


private:

	std::string		_name;
	int				_grade;
};

std::ostream&	operator<<(std::ostream& output_stream, Bureaucrat const &bureaucrat);

#endif