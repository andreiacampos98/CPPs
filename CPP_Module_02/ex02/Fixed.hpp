#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _fp_value;
		static const int _fract_bits;
	public:
		Fixed(void); //default constructor
		Fixed(const Fixed &copy); //copy default constructor
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void); //deconstrutor

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed &operator = (const Fixed &src); //assigment operator constructor
		bool operator<(const Fixed &src) const; 
		bool operator>(const Fixed &src) const; 
		bool operator<=(const Fixed &src) const; 
		bool operator>=(const Fixed &src) const; 
		bool operator==(const Fixed &src) const; 
		bool operator!=(const Fixed &src) const; 

		Fixed operator+(const Fixed &src); 
		Fixed operator-(const Fixed &src); 
		Fixed operator*(const Fixed &src); 
		Fixed operator/(const Fixed &src); 

		Fixed& operator++(); //prefix
		Fixed operator++(int); //postfix
		Fixed& operator--(); //prefix
		Fixed operator--(int); //postfix

		static Fixed&       max(Fixed& f1, Fixed& f2);
		static Fixed&       min(Fixed& f1, Fixed& f2);
		static const Fixed& max(const Fixed& f1, const Fixed& f2);
		static const Fixed& min(const Fixed& f1, const Fixed& f2);

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& src);

#endif

/*https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170*/
