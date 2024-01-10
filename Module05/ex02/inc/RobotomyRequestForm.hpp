#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{

public:

// Constructors & Destructor
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

// Getters
	std::string		getTarget() const;

//Member functions
	void	execute(Bureaucrat const & executor) const;

private:

	std::string		_target;

};

#endif