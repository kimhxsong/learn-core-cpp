#include "Fixed.hpp"

#include <iostream>

int const Fixed::_kFractional = 8;

Fixed::Fixed()
  : _raw(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::~Fixed() {
  std::cout << "Desctructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const & rhs) {
  std::cout << "Assignation operator called" << std::endl;
  _raw = getRawBits(rhs);
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return _raw;
}

int Fixed::getRawBits(Fixed const & rhs) const {
  std::cout << "getRawBits member function called" << std::endl;
  return rhs._raw;
}

void  Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _raw = raw;
}