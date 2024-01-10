#include "Form.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Form::Form():_name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form " << _name << " has been created with default grades 150." << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw(Form::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw(Form::GradeTooLowException());
	else
	{
		this->setName(name);
		this->setSignedStatus(false);
		this->setGradeToSign(gradeToSign);
		this->setGradeToExecute(gradeToExecute);
		std::cout << "Form " << _name << " has been created with grade to sign "
					<< gradeToSign << " and grade to execute "
					<< gradeToExecute << "." << std::endl;
	}
}

Form::Form(const Form& copy): _name(copy.getName() + "_copy")
{
	this->setSignedStatus(copy.getSignedStatus());
	this->setGradeToSign(copy.getGradeToSign());
	this->setGradeToExecute(copy.getGradeToExecute());
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
		this->_name = src.getName();
		this->_isSigned = src.getSignedStatus();
		this->_gradeToSign = src.getGradeToSign();
		this->_gradeToExecute = src.getGradeToExecute();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters

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


// Setters

void	Form::setName(const std::string name)
{
	this->_name = name;
}

void	Form::setSignedStatus(bool const status)
{
	this->_isSigned = status;
	// std::cout << "Form " << _name << "'s signed status has been set to "
	// 			<< status << "." << std::endl;
}

void	Form::setGradeToSign(const int grade)
{
	this->_gradeToSign = grade;
}

void	Form::setGradeToExecute(const int grade)
{
	this->_gradeToExecute = grade;
}


// Member functions

void	Form::beSigned(Bureaucrat& ref)
{
	if (ref.getGrade() >= this.getGradeToSign())
	{
		this.setSignedStatus(true);
		std::cout << "Form " << _name << " has been signed by Bureaucrat "
					<< ref.getName() << "." << std::endl;
	}
	else
		throw(Form::GradeTooLowException());
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
	output_stream << "Form" << form.getName() << ", grade to sign is "
				<< form.getGradeToSign() << " and grade to execute is "
				<< form.getGradeToExecute() << ". Signed status : " << form.getSignedStatus()
				<< std::endl;
	return (output_stream);
}
