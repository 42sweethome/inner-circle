#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>

class conversion
{
	public:
	int	i;
	char c;
	float f;
	double d;

	conversion();
	conversion(char src);
	conversion(int src);
	conversion(float src);
	conversion(double src);
};

#endif
