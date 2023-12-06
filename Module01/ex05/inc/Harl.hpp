#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <cstdlib> // EXIT_SUCCESS / EXIT_FAILURE
#include <map>

class Harl
{

public:
	Harl();
	~Harl();

	void	complain( std::string level );

private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif