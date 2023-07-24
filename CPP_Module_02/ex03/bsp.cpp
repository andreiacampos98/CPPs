#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float A = Point::area(a, b, c);
    float A1 = Point::area(a, b, point);
    float A2 = Point::area(a, c, point);
    float A3 = Point::area(c, b, point);
    return(A == (A1 + A2 +A3));
}

std::string  boolToString(bool value)
{
	if (value)
        return ("True");
    return ("False");
}
