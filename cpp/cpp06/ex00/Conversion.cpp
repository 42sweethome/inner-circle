#include "Conversion.hpp"

void classify_ntype(t_info *conv_info)
{
	if (conv_info->isprint)
		std::cout << "char: Non displayable" << std::endl;
	else if (conv_info->dounum < 0 || conv_info->dounum > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char> (conv_info->dounum) << std::endl;
	if (conv_info->dounum > INT_MAX || conv_info->dounum < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int> (conv_info->dounum) << std::endl;
	std::cout << "float: " << static_cast<float> (conv_info->dounum);
	if ((conv_info->p_zero && conv_info->point < 6) || conv_info->point == 6)
		std::cout << ".0f"<< std::endl;
	else
		std::cout << "f"<< std::endl;
	std::cout << std::setprecision(15);
	std::cout << "double: " << conv_info->dounum;
	if (conv_info->p_zero)
		std::cout << ".0"<< std::endl;
	else
		std::cout << std::endl;
}

void classify_type(char *argv, t_info *conv_info)
{
	if (conv_info->pseudo)
	{
		if (argv[0] == '+')
			argv++;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << argv << "f" << std::endl;
		std::cout << "double: " << argv << std::endl;
		return ;
	}
	else if (conv_info->isstring)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	else if (conv_info->ischar)
	{
		std::cout << "char: " << argv[0] << std::endl;
		std::cout << "int: " << static_cast<int> (argv[0]) <<std::endl;
		std::cout << "float: " << static_cast<float> (argv[0]) << std::endl;
		std::cout << "double: " << static_cast<double> (argv[0]) << std::endl;
		return ;
	}
	classify_ntype(conv_info);
}

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
	conv_info->dounum = strtod(argv, NULL);
	std::cout << conv_info->dounum << std::endl;
	if (atoi(argv) == conv_info->dounum)
		conv_info->p_zero = 1;
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
		conv_info->point = idx;
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

void check_param(char *argv, t_info *conv_info)
{
	int i;
	int ret;
	
	ret = 1;
	i = -1;
	while (argv[++i])
	{
		ret = check_num(argv[i]);
		if (!ret)
		{
			ret = get_num_info(argv, i, conv_info);
			if (ret)
				break ;
		}
		else
			break ;
	}
	if (ret)
		check_string(&argv, conv_info);
	else
		check_isprint(argv, conv_info);
	classify_type(argv, conv_info);
	return ;
}

void init_flag(t_info *conv_info)
{
	conv_info->sign = 0;
	conv_info->point = 0;
	conv_info->isfloat = 0;
	conv_info->pseudo = 0;
	conv_info->isstring = 0;
	conv_info->ischar = 0;
	conv_info->isprint = 0;
	conv_info->p_zero = 0;
}

int	main(int argc, char **argv)
{
	t_info conv_info;

	if (argc != 2)
	{
		std::cout << "Put only one argument!" << std::endl;
		return (-1);
	}
	init_flag(&conv_info);
	check_param(argv[1], &conv_info);
	return (0);
}
