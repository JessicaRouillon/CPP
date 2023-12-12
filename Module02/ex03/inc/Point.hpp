#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# include <iostream>

class Point
{

public:
	Point();
	Point(const float nb1, const float nb2);
	Point(const Point& copy);
	~Point();

	Point& operator=(const Point& src);

	const Fixed	getX( void ) const;
	const Fixed	getY( void ) const;

	bool bsp( Point const a, Point const b, Point const c, Point const point);

private:

	Fixed const	_x;
	Fixed const	_y;
};

#endif