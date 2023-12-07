#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:

	Fixed(); // constructor
	Fixed( const int intNb ); // constructor
	Fixed( const float flNb ); // constructor
	Fixed(const Fixed &copy); // copy constructor
	Fixed& operator=(const Fixed &src); // move assignment operator
	~Fixed(); // destructor

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

private:

	int					_fixedPointNbValue;
	static const int	_fractBitsNb;
};

std::ostream	&operator<<(std::ostream &op, Fixed const &fixed);

#endif