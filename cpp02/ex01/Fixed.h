#ifndef EX00__FIXED_H_
#define EX00__FIXED_H_

#include <iostream>
#include <cmath>

class Fixed {
 private:
  int value_;
  static const int fraction_ = 8;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed(int value);
  Fixed(float value);
  Fixed& operator = (const Fixed& other);
  ~Fixed();

 public:
  int getRawBits() const;
  void setRawBits(const int raw);

  float toFloat() const;
  int toInt() const;
};

std::ostream& operator << (std::ostream& o, Fixed const& f);

#endif //EX00__FIXED_H_
