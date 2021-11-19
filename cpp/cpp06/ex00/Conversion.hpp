#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <climits>
# include <iomanip>

 typedef struct s_info {
	int sign;
	int point;
	int isfloat;
	int pseudo; //
	int isstring; //
	int ischar; //
	int isprint; //
	int p_zero;
	double dounum;
} t_info;


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
