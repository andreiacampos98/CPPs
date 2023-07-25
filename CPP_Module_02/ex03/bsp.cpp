#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = Point::area(a, b, c);
    Fixed A1 = Point::area(a, b, point);
    Fixed A2 = Point::area(a, c, point);
    Fixed A3 = Point::area(c, b, point);
    return(A == (A1 + A2 + A3));
}
