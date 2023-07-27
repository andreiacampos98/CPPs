#ifndef EX00__FIXED_H_
#define EX00__FIXED_H_

#include <iostream>
#include <cmath>
#include <stdexcept>

class Fixed {
 private:
  int value_;
  static const int fraction_ = 8;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed(int value);
  Fixed(float value);

  ~Fixed();

  Fixed& operator = (const Fixed& other);

 public:
  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  bool operator<(const Fixed& rhs) const;
  bool operator<=(const Fixed& rhs) const;
  bool operator>(const Fixed& rhs) const;
  bool operator>=(const Fixed& rhs) const;
  bool operator==(const Fixed& rhs) const;
  bool operator!=(const Fixed& rhs) const;

 public:
  static Fixed& min(Fixed& lhs, Fixed& rhs);
  static const Fixed& min(const Fixed& lhs, const Fixed& rhs);

  static Fixed& max(Fixed& lhs, Fixed& rhs);
  static const Fixed& max(const Fixed& lhs, const Fixed& rhs);


  int getRawBits() const;
  void setRawBits(const int raw);

  float toFloat() const;
  int toInt() const;
};

Fixed operator-(const Fixed& lhs, const Fixed& rhs);
Fixed operator+(const Fixed& lhs, const Fixed& rhs);
Fixed operator*(const Fixed& lhs, const Fixed& rhs);
Fixed operator/(const Fixed& lhs, const Fixed& rhs);

std::ostream& operator << (std::ostream& o, Fixed const& f);

#endif //EX00__FIXED_H_
