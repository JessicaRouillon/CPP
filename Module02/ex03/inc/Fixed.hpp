#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>

class Fixed
{
public:

	Fixed(); // constructor
	Fixed( const int intNb ); // constructor
	Fixed( const float flNb ); // constructor
	Fixed(const Fixed& copy); // copy constructor
	Fixed& operator=(const Fixed& src); // move assignment operator. overload operator
	~Fixed(); // destructor

	// Comparison operators
	bool	operator>(Fixed other) const;
	bool	operator<(Fixed other) const;
	bool	operator>=(Fixed other) const;
	bool	operator<=(Fixed other) const;
	bool	operator==(Fixed other) const;
	bool	operator!=(Fixed other) const;

	// Arithmetic operators
	float	operator+(const Fixed other);
	float	operator-(const Fixed other);
	float	operator*(const Fixed other);
	float	operator/(const Fixed other);

	// Increment-Decrement operators
	Fixed	operator++(void);
	Fixed	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	// Getter-Setter functions
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	// Conversion functions
	float toFloat( void ) const;
	int toInt( void ) const;

	// Public overloaded member functions
	static Fixed& min(Fixed& nb1, Fixed& nb2);
	static const Fixed& min(const Fixed& nb1, const Fixed& nb2);
	static Fixed& max(Fixed& nb1, Fixed& nb2);
	static const Fixed& max(const Fixed& nb1, const Fixed& nb2);

private:

	int					_fixedPointNbValue;
	static const int	_fractBitsNb;
};

std::ostream	&operator<<(std::ostream& output_stream, const Fixed& fixed);

#endif