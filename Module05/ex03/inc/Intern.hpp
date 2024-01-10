#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Intern
{

public:

// Constructors & Destructor
	Intern();
	Intern(const Intern& copy);
	~Intern();

	Intern& operator=(const Intern& src);

// Member function
	AForm*	makeForm(const std::string formName, const std::string formTarget);

// Exception
	class Exception : public std::exception
	{
		public :
			const char*	what() const throw();
	};

};

#endif