//
// Created by Alexandru Mitcul on 13/07/2023.
//

#include "Point.h"

Point::Point(): x_(0), y_(0) {}

Point::Point(const float x, const float y): x_(x), y_(y) {}

Point::Point(const Point &other): x_(other.x_), y_(other.y_) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
  if (this != &other) {
    (Fixed)this->x_ = other.get_x();
    (Fixed)this->y_ = other.get_y();
  }
  return *this;
}

Fixed Point::get_x() const {
  return x_;
}

Fixed Point::get_y() const {
  return y_;
}
