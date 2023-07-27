//
// Created by Alexandru Mitcul on 29/06/2023.
//

#ifndef EX00__FIXED_H_
#define EX00__FIXED_H_

class Fixed {
 private:
  int value_;
  static const int fraction_ = 8;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator = (const Fixed& other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif //EX00__FIXED_H_
