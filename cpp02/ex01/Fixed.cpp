#include "Fixed.h"

Fixed::Fixed(): value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): value_(value << fraction_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value):
  value_(std::roundf(value * (1 << fraction_))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  this->setRawBits(other.value_);
}

Fixed &Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->value_ = other.value_;
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

void Fixed::setRawBits(const int raw) {
//  std::cout << "setRawBits member function called" << std::endl;
  this->value_ = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(value_) / (1 << fraction_);
}

int Fixed::toInt() const {
  return value_ >> fraction_;
}

std::ostream& operator << (std::ostream& o, Fixed const& f) {
  o << f.toFloat();
  return o;
}
