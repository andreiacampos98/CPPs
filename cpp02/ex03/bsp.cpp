
#include "Point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed u, v, w;

  u = (b.get_y() - c.get_y()) * (point.get_x() - c.get_x()) +
      (c.get_x() - b.get_x()) * (point.get_y() - c.get_y());
  v = (c.get_y() - a.get_y()) * (point.get_x() - c.get_x()) +
      (a.get_x() - c.get_x()) * (point.get_y() - c.get_y());
  w = Fixed(1) - u - v;

  return u >= 0 && v >= 0 && w >= 0;
}
