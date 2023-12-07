#include "Fixed.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

const int Fixed::_fractBitsNb = 8;

// Constructors
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

// Converts the integer to the corresponding fixed-point value
Fixed::Fixed(const int intNb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNbValue = intNb << this->_fractBitsNb;
}

// Converts the float-point value to the corresponding fixed-point value
Fixed::Fixed(const float flNb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNbValue = roundf(flNb * (1 << this->_fractBitsNb));

}

// Copy constructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Move assignment operator
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointNbValue = src.getRawBits();
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPointNbValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointNbValue = raw;
}

// Converts the fixed-point value to a floating-point value
float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPointNbValue / (float)(1 << this->_fractBitsNb));
}

// Converts the fixed-point value to an int
int		Fixed::toInt( void ) const
{
	return (this->_fixedPointNbValue >> this->_fractBitsNb);
}


/********************************************************************************/
/*************************** ADDITIONAL FUNCTIONS *******************************/
/********************************************************************************/

// Definition of operator "<<" to output Fixed class instances
std::ostream		&operator<<(std::ostream &output_stream, const Fixed &fixed)
{
	output_stream << fixed.toFloat();
	return (output_stream);
}
