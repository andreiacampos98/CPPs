#include "Fixed.hpp"

const int	Fixed::_fract_bits = 8;

Fixed::Fixed(void) : _fp_value(0) //default constructor defination _fp_value default value is 0
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value * (1 << Fixed::_fract_bits));
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << Fixed::_fract_bits)));
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(copy._fp_value); //used assignment operator
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) //operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fp_value = src.getRawBits(); /*setRawBits(src.getRawBits());*/
	return(*this);
}


/*Comparison Operators*/

bool Fixed::operator<(const Fixed &src) const
{
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>(const Fixed &src) const
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const
{
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const
{
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const
{
	return !(*this == src);
}


/*Arithmetic operators*/

Fixed Fixed::operator+(const Fixed &src) const
{
	return (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return (this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return (this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
	return (this->toFloat() / src.toFloat());
}

/*Increment/Decrement operators*/

Fixed& Fixed::operator++()
{
	this->_fp_value++;
	return (*this);
}

Fixed Fixed::operator++(int) //postfix
{
	Fixed temp = *this;
	this->_fp_value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->_fp_value--;
	return (*this);
}

Fixed Fixed::operator--(int) //postfix
{
	Fixed temp = *this;
	this->_fp_value--;
	return (temp);
}


/*Min and Max functions*/

Fixed&       Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed&       Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

/*Functions*/
		
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fp_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fp_value / (float)(1 << Fixed::_fract_bits));
}

int Fixed::toInt( void ) const
{
	return(this->_fp_value >> Fixed::_fract_bits);
}

std::ostream& operator<<(std::ostream& os, Fixed const& src)
{
	os << src.toFloat();
	return(os);
}

/*https://www.youtube.com/watch?v=BvR1Pgzzr38*/
/*https://www.youtube.com/watch?v=mS9755gF66w&list=RDCMUCQ-W1KE9EYfdxhL6S4twUNw&index=2*/
