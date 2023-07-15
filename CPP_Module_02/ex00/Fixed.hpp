#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int _fp_value;
		static const int _fract_bits;
	public:
		Fixed(void); //default constructor
		Fixed(const Fixed &copy); //copy default constructor
		Fixed & operator = (const Fixed &src); //assigment operator constructor
		~Fixed(void); //deconstrutor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
