#include "Bureaucrat.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat Default has entered the office with default grade 150." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade = grade;
		std::cout << "Bureaucrat " << name
					<< " has entered the office with grade "
					<< grade << "." << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy.getName() + "_copy")
{
	this->_grade = copy.getGrade();
	std::cout << "A deep copy of Bureaucrat " << _name << " with grade " << _grade << " has been made." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " with grade " << _grade << " has left the office." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& src)
{
	(void)src;
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters

std::string		Bureaucrat::getName() const
{
	return (this->_name);
}

int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}


// Increment & Decrement

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade -= 1;
		std::cout << "Bureaucrat " << _name
					<< "'s grade has been incremented by 1 and now has a grade of "
					<< _grade << "!" << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade += 1;
		std::cout << "Bureaucrat " << _name
					<< "'s grade has been decremented by 1 and now has a grade of "
					<< _grade << "..." << std::endl;
	}
}


// Member functions

void	Bureaucrat::signForm(const AForm& form) const
{
	if (form.getSignedStatus() == true)
	{
		std::cout << "Bureaucrat " << _name << " signed AForm " << form.getName()
					<< "." << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << _name << " could not sign AForm " << form.getName()
					<< " due to being a loser." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (form.getSignedStatus() == false)
		throw (AForm::UnsignedException());
	else if (this->getGrade() > form.getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else
		std::cout << "\033[0;32m" << "Bureaucrat " << _name << " has executed " << form.getName() << " form." << "\033[0m" << std::endl;
}


// Exceptions

const char*		Bureaucrat::Exception::what() const throw()
{
	return ("\033[0;31mDefault Bureaucrat Exception\n\033[0m");
}

const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade cannot be higher than 1.\n\033[0m");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade cannot be lower than 150.\n\033[0m");
}


/********************************************************************************/
/*************************** ADDITIONAL FUNCTIONS *******************************/
/********************************************************************************/

// Definition of operator "<<" to output Bureaucrat class instances

std::ostream&	operator<<(std::ostream& output_stream, const Bureaucrat& bureaucrat)
{
	output_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (output_stream);
}
