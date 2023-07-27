//
// Created by Alexandru Mitcul on 29/06/2023.
//
#include <iostream>

#include "Fixed.h"

Fixed::Fixed(): value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->value_ = other.getRawBits();
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
