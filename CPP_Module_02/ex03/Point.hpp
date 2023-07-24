#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include "math.h"

class Point{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const float &valuex, const float &valuey);
		Point(const Point &copy);
		Point &operator = (const Point &src);
		~Point();

		float getX( void ) const;
		float getY( void ) const;
		static float area(const Point &a, const Point &b, const Point &c);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
