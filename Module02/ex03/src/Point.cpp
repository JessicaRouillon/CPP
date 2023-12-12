#include "Point.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Point::Point(): _x(0), _y(0)
{
}

Point::Point():_x(nb1), _y(nb2)
{
}

Point::Point(const Point& copy)
{
	*this = copy;
}

Point::~Point()
{
}

Point&	Point::operator=(const Point& src)
{
	if (this != &src)
	{
		this->_x = src.getX();
		this->_y = src.getY();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}
