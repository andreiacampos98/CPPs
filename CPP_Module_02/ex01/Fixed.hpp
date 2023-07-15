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
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy); //copy default constructor
		Fixed & operator = (const Fixed &src); //assigment operator constructor
		~Fixed(void); //deconstrutor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& src);

#endif

/*https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170*/
