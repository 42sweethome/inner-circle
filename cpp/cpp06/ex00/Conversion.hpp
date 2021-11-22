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
	int pseudo;
	int isstring;
	int ischar;
	int isprint;
	int d_zero;
	int f_zero;
	float fnum;
	double dounum;
} t_info;


class conversion // canonical form check????
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

int ft_strlen(char *argv);
void check_isprint(char *argv, t_info *conv_info);
int check_pseudo(char **argv);
void check_string(char **argv, t_info *conv_info);
int get_num_info(char *argv , int idx, t_info *conv_info);
int check_num(char c);
void classify_type(char *argv, t_info *conv_info);

#endif
