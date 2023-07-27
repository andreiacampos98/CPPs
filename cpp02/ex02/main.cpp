#include <iostream>
#include "Fixed.h"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

//	std::cout << a << " " << b << std::endl;
//	Fixed f = a + 4.2f + b;
//
//	std::cout << f << std::endl;
//
//	std::cout << (f > 4.2f) << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}
