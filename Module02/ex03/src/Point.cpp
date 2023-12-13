#include "Point.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
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
		(Fixed)this->_x = src.getX();
		(Fixed)this->_y = src.getY();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

Fixed	Point::getX( void ) const
{
	return (_x);
}

Fixed	Point::getY( void ) const
{
	return (_y);
}

/********************************************************************************/
/*************************** ADDITIONAL FUNCTIONS *******************************/
/********************************************************************************/

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	productAB = ((a.getX().toFloat() - point.getX().toFloat()) * (b.getY().toFloat() - point.getY().toFloat())
		 - (a.getY().toFloat() - point.getY().toFloat()) * (b.getX().toFloat() - point.getX().toFloat()));

	Fixed	productAC = ((c.getX().toFloat() - point.getX().toFloat()) * (a.getY().toFloat() - point.getY().toFloat())
		 - (c.getY().toFloat() - point.getY().toFloat()) * (a.getX().toFloat() - point.getX().toFloat()));

	Fixed	productBC = ((b.getX().toFloat() - point.getX().toFloat()) * (c.getY().toFloat() - point.getY().toFloat())
		 - (b.getY().toFloat() - point.getY().toFloat()) * (c.getX().toFloat() - point.getX().toFloat()));

	if ((point.getX().toFloat() == a.getX().toFloat() && point.getY().toFloat() == a.getY().toFloat())
		|| (point.getX().toFloat() == b.getX().toFloat() && point.getY().toFloat() == b.getY().toFloat())
		|| (point.getX().toFloat() == c.getX().toFloat() && point.getY().toFloat() == c.getY().toFloat()))
		return (false);

	return ((productAB > 0 && productAC > 0 && productBC > 0)
			|| (productAB < 0 && productAC < 0 && productBC < 0));
}
