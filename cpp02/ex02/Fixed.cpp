#include "Fixed.h"

Fixed::Fixed(): value_(0) {}

Fixed::Fixed(const int value): value_(value << fraction_) {}

Fixed::Fixed(const float value):
  value_(std::roundf(value * (1 << fraction_))) {}

Fixed::Fixed(const Fixed& other) {
  this->setRawBits(other.value_);
}

Fixed &Fixed::operator=(const Fixed& other) {
  if (this != &other)
    this->value_ = other.value_;
  return *this;
}

Fixed::~Fixed() {}

/*
 * Increment/Decrement operators
 */

Fixed Fixed::operator++(int) {
  Fixed result(*this);
  ++this->value_;
  return result;
}

Fixed &Fixed::operator++() {
  ++this->value_;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed result(*this);
  --this->value_;
  return result;
}

Fixed &Fixed::operator--() {
  --this->value_;
  return *this;
}

/*
 * Arithmetic operators
 */

Fixed operator+(const Fixed& lhs, const Fixed &rhs) {
  return Fixed(lhs.toFloat() + rhs.toFloat());
}

Fixed operator-(const Fixed& lhs, const Fixed &rhs) {
  return Fixed(lhs.toFloat() - rhs.toFloat());
}

Fixed operator*(const Fixed& lhs, const Fixed &rhs) {
  return Fixed(lhs.toFloat() * rhs.toFloat());
}

Fixed operator/(const Fixed& lhs, const Fixed &rhs) {
  // Does division by zero need to be taken care of?
  return Fixed(lhs.toFloat() / rhs.toFloat());
}

/*
 * Comparison operators
 */

bool Fixed::operator<(const Fixed& rhs) const {
  return this->getRawBits() < rhs.getRawBits();
}
bool Fixed::operator<=(const Fixed& rhs) const {
  return this->getRawBits() <= rhs.getRawBits();
}
bool Fixed::operator>(const Fixed& rhs) const {
  return this->getRawBits() > rhs.getRawBits();
}
bool Fixed::operator>=(const Fixed& rhs) const {
  return this->getRawBits() >= rhs.getRawBits();
}
bool Fixed::operator==(const Fixed& rhs) const {
  return this->getRawBits() == rhs.getRawBits();
}
bool Fixed::operator!=(const Fixed& rhs) const {
  return this->getRawBits() != rhs.getRawBits();
}

/*
 *
 */

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
  if (lhs < rhs)
    return lhs;
  return rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
  if (lhs < rhs)
    return lhs;
  return rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
  if (lhs > rhs)
    return lhs;
  return rhs;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) {
  if (lhs > rhs)
    return lhs;
  return rhs;
}

int Fixed::getRawBits() const {
  return value_;
}

void Fixed::setRawBits(const int raw) {
  this->value_ = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(value_) / (1 << fraction_);
}

int Fixed::toInt() const {
  return value_ >> fraction_;
}

std::ostream& operator<<(std::ostream& o, Fixed const& f) {
  o << f.toFloat();
  return o;
}
