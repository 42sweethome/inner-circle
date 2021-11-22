
#include "Conversion.hpp"

int ft_strlen(char *argv)
{
	int i;
	
	i = -1;
	while (argv[++i])
		;
	return (i);
}

void check_isprint(char *argv, t_info *conv_info)
{
	double d_tmp = 0;
	float f_tmp = 0;

	if (conv_info->point <= 6)
		f_tmp = pow(0.1, 6 - conv_info->point);
	if (conv_info->point <= 15)
		d_tmp = pow(0.1, 15 - conv_info->point);
	conv_info->dounum = strtod(argv, NULL);
	conv_info->fnum = strtof(argv, NULL);
	if (round(abs(conv_info->dounum - atoi(argv)) * pow(10, 15 - conv_info->point))\
						/ pow(10, 15 - conv_info->point) <= d_tmp)
		conv_info->d_zero = 1;
	if (round(abs(conv_info->fnum - atoi(argv)) * pow(10, 6 - conv_info->point))\
						/ pow(10, 6 - conv_info->point) <= f_tmp)
		conv_info->f_zero = 1;
	if ((conv_info->dounum >= 0 && conv_info->dounum <= 31) \
	|| conv_info->dounum == 127)
		conv_info->isprint = 1;
}

int check_pseudo(char **argv)
{
	std::string pseudo;

	pseudo = static_cast<std::string> (*argv);
	if (!pseudo.compare("-inff") || !pseudo.compare("+inff") \
		||!pseudo.compare("nanf") || !pseudo.compare("inff"))
	{
		(*argv)[(ft_strlen(*argv) - 1)] = 0;
		return (1);
	}
	else if (!pseudo.compare("-inf") || !pseudo.compare("+inf") \
		||!pseudo.compare("inf") || !pseudo.compare("nan"))
		return (1);
	return (0);
}

void check_string(char **argv, t_info *conv_info)
{
	if ((*argv)[0] != 0 && (*argv)[1] != 0)
	{
		if (check_pseudo(argv))
			conv_info->pseudo = 1;
		else
			conv_info->isstring = 1;
	}
	else
		conv_info->ischar = 1;
}

int get_num_info(char *argv , int idx, t_info *conv_info)
{
	if (argv[idx] == '+' || argv[idx] == '-')
	{
		if (idx == 0)
			conv_info->sign = 1;
		else
			return (1);
	}
	else if (argv[idx] == '.')
	{
		if ((conv_info->sign && idx == 1) || idx == 0 \
		|| conv_info->point || argv[idx + 1] == 0 \
		|| argv[idx + 1] == 'f')
			return (1);
		conv_info->point = idx - conv_info->sign;
	}
	else if (argv[idx] == 'f')
	{
		if (argv[idx + 1] != 0 || conv_info->point == 0)
			return (1);
		conv_info->isfloat = 1;
	}
	return (0);
}

int check_num(char c)
{
	if (c == '+' || c == '-' || c == '.' \
	|| c == 'f' || (c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}
