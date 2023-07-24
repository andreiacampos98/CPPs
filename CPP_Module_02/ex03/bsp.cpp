#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	//float A = Point::area(a, b, c);
    float A1 = Point::area(a, b, point);
    float A2 = Point::area(a, c, point);
    float A3 = Point::area(c, b, point);
    return ((A1 < 0 && A2 < 0 && A3 < 0) || (A1 > 0 && A2 > 0 && A3 > 0));
    //return(A == (A1 + A2 + A3));
}
