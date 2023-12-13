#include "Fixed.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

const int Fixed::_fractBitsNb = 8;

// Constructors
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

	// Converts the integer to the corresponding fixed-point value
Fixed::Fixed(const int intNb)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNbValue = intNb << this->_fractBitsNb;
}

	// Converts the float-point value to the corresponding fixed-point value
Fixed::Fixed(const float flNb)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNbValue = roundf(flNb * (1 << this->_fractBitsNb));

}

	// Copy constructor
Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Move assignment operator: Overloaded operators
Fixed&	Fixed::operator=(const Fixed& src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointNbValue = src.getRawBits();
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Comparison operators

bool	Fixed::operator>(Fixed other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(Fixed other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(Fixed other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(Fixed other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(Fixed other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(Fixed other) const
{
	return (this->toFloat() != other.toFloat());
}


// Arithmetic operators

float	Fixed::operator+(const Fixed other)
{
	return(this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed other)
{
	return(this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed other)
{
	return(this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed other)
{
	return(this->toFloat() / other.toFloat());
}


// Increment-Decrement operators

Fixed	Fixed::operator++(void)
{
	this->_fixedPointNbValue++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_fixedPointNbValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++this->_fixedPointNbValue;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--this->_fixedPointNbValue;
	return (tmp);
}

// Getter-Setter functions

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPointNbValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointNbValue = raw;
}


// Conversion functions

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


// Public overloaded member functions

Fixed&	Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1.toFloat() <= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

Fixed&	Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1.toFloat() >= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

const Fixed&	Fixed::min(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1.toFloat() <= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

const Fixed&	Fixed::max(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1.toFloat() >= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

/********************************************************************************/
/*************************** ADDITIONAL FUNCTIONS *******************************/
/********************************************************************************/

// Definition of operator "<<" to output Fixed class instances
std::ostream		&operator<<(std::ostream& output_stream, const Fixed& fixed)
{
	output_stream << fixed.toFloat();
	return (output_stream);
}
