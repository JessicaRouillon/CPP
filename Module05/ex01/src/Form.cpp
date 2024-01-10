#include "Form.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Form::Form():
		_name("Default"),
		_isSigned(false),
		_gradeToSign(150),
		_gradeToExecute(150)
{
	std::cout << "Form " << _name << " has been created with default grades 150." << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute):
		_name(name),
		_isSigned(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw(Form::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw(Form::GradeTooLowException());
	else
	{
		std::cout << "Form " << _name << " has been created with grade to sign "
					<< gradeToSign << " and grade to execute "
					<< gradeToExecute << "." << std::endl;
	}
}

Form::Form(const Form& copy):
		_name(copy.getName() + "_copy"),
		_isSigned(copy.getSignedStatus()),
		_gradeToSign(copy.getGradeToSign()),
		_gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "A copy of Form " << _name << " has been made." << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << " has been destroyed." << std::endl;
}

Form	&Form::operator=(const Form& src)
{
	std::cout << "Form " << _name << "'s assignment operator called." << std::endl;
	if (this != &src)
	{
		this->_isSigned = src.getSignedStatus();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters & Setters

std::string		Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignedStatus() const
{
	return (this->_isSigned);
}

int		Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::setSignedStatus(bool const status)
{
	this->_isSigned = status;
	std::cout << "Form " << _name << "'s signed status has been set to "
				<< status << "." << std::endl;
}


// Member functions

void	Form::beSigned(Bureaucrat& ref)
{
	// std::cout << ">> Bureaucrat's grade is " << ref.getGrade() << " and sign grade is " << this->getGradeToSign() << std::endl;
	if (this->getSignedStatus() == true)
		std::cout << "Form " << _name << " has already been signed." << std::endl;
	else if (ref.getGrade() > this->getGradeToSign())
		throw(Form::GradeTooLowException());
	else
	{
		this->setSignedStatus(true);
		std::cout << "Form " << _name << " has been signed by Bureaucrat "
					<< ref.getName() << "." << std::endl;
	}
}


// Exceptions

const char*		Form::Exception::what() const throw()
{
	return ("\033[0;31mDefault Form Exception\n\033[0m");
}

const char*		Form::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade cannot be higher than 1.\n\033[0m");
}

const char*		Form::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade cannot be lower than 150.\n\033[0m");
}

/********************************************************************************/
/*************************** ADDITIONAL FUNCTIONS *******************************/
/********************************************************************************/

// Definition of operator "<<" to output Bureaucrat class instances

std::ostream&	operator<<(std::ostream& output_stream, Form const &form)
{
	output_stream << "Form " << form.getName() << ", grade to sign is "
				<< form.getGradeToSign() << " and grade to execute is "
				<< form.getGradeToExecute() << ". Signed status : " << form.getSignedStatus()
				<< std::endl;
	return (output_stream);
}
