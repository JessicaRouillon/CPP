#include "Harl.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Harl::Harl()
{
}

Harl::~Harl()
{
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Private member functions

void	Harl::debug(void)
{
	std::cout << "\033[1m" << "[DEBUG] " << "\033[0m"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
				<< std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "\033[1m" << "[INFO] " << "\033[0m"
				<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
				<< std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "\033[1m" << "[WARNING] " << "\033[0m"
				<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
				<< std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "\033[1m" << "[ERROR] " << "\033[0m"
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl << std::endl;
}


// Public member function

void	Harl::complain( std::string level )
{
	void	(Harl::*functionPointers[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		complaint[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	size_t	i = 0;
	for(; i < 4; i++)
	{
		if (complaint[i] == level)
			break ;
	}
	switch (i)
	{
		case 0:
			(this->*functionPointers[0])();
		case 1:
			(this->*functionPointers[1])();
		case 2:
			(this->*functionPointers[2])();
		case 3:
			(this->*functionPointers[3])();
			break ;
		default : 
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
