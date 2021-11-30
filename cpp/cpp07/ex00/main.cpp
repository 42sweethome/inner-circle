#include "Function.hpp"
//template <typename function>

template <class function>
void swap(function &a, function &b)
{
	function temp;
    temp = a;
    a = b;
    b = temp;
}

template <class function>
function min(function &a, function &b)
{
	if (a == b)
		return (b);
	else if (a < b)
		return (a);
	else
		return (b);
}

template <class function>
function max(function &a, function &b)
{
	if (a == b)
		return (b);
	else if (a < b)
		return (b);
	else
		return (a);
}

int main( void )
{
	int a = 2;
	int b = 3;

	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
	return 0;
}
