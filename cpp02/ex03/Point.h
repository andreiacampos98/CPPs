//
// Created by Alexandru Mitcul on 13/07/2023.
//

#ifndef EX03__POINT_H_
#define EX03__POINT_H_

#include "Fixed.h"

class Point {
 private:
  const Fixed x_;
  const Fixed y_;

 public:
  Point();
  Point(const float x, const float y);
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();

  Fixed get_x() const;
  Fixed get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif //EX03__POINT_H_
