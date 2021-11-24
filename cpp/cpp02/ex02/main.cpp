#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "ture is 1, false is 0" << std::endl;
	std::cout << "a	 : " << a << ", b	 : " << b << std::endl;
	std::cout << "a < b	 : " << (a < b) << std::endl;
	std::cout << "a > b	 : " << (a > b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;

	std::cout << "a++	= " << a++ << std::endl;
	std::cout << "a	= " << a << std::endl;
	std::cout << "++a	= " << ++a << std::endl;
	std::cout << "a	= " << a << std::endl;
	std::cout << "a--	= " << a-- << std::endl;
	std::cout << "a	= " << a << std::endl;
	std::cout << "--a	= " << --a << std::endl;
	std::cout << "a	= " << a << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << "b / a = " << (b / a) << std::endl;

	std::cout << "b	= " << b << std::endl;

	Fixed c;
	Fixed d(123);

	std::cout << "max( a, b ) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min( a, b ) = " << Fixed::min( a, b ) << std::endl;
	std::cout << "max( c, d ) = " << Fixed::max( c, d ) << std::endl;
	std::cout << "min( c, d ) = " << Fixed::min( c, d ) << std::endl;

	return (0);
}