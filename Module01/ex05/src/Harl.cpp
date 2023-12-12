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
	std::cout << std::endl << "\033[1m" << "[DEBUG] " << "\033[0m"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout << std::endl << "\033[1m" << "[INFO] " << "\033[0m"
				<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << std::endl << "\033[1m" << "[WARNING] " << "\033[0m"
				<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout << std::endl << "\033[1m" << "[ERROR] " << "\033[0m"
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}


// Public member function

void	Harl::complain( std::string level )
{
	void	(Harl::*functionPointers[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		complaint[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(size_t	i = 0; i < 4; i++)
	{
		if (complaint[i] == level)
			(this->*functionPointers[i])();
	}
	if (level != complaint[0] && level != complaint[1] && level != complaint[2] && level != complaint[3])
		std::cout << std::endl << "\033[33m" << "/!\\ Incorrect input." << "\033[0m";
}
