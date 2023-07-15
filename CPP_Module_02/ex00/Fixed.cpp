#include "Fixed.hpp"

const int	Fixed::_fract_bits = 8;

Fixed::Fixed(void) : _fp_value(0) //default constructor defination _fp_value default value is 0
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy; //used assignment operator
}

Fixed &Fixed::operator =(const Fixed &src) //operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fp_value = src.getRawBits();
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fp_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}


/*https://www.youtube.com/watch?v=BvR1Pgzzr38*/
