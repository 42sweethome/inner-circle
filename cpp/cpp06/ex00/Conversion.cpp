#include "Conversion.hpp"

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
	if (ret && argv[0])
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
	conv_info->f_zero = 0;
	conv_info->d_zero = 0;
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
