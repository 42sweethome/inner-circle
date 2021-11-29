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
	std::cout << "float: " << conv_info->fnum;
	if ((conv_info->f_zero && conv_info->point <= 6))
		std::cout << ".0f"<< std::endl;
	else
		std::cout << "f"<< std::endl;
	std::cout << std::setprecision(15);
	std::cout << "double: " << conv_info->dounum;
	if (conv_info->d_zero && conv_info->point <= 15)
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
		std::cout << "float: " << static_cast<float> (argv[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double> (argv[0]) << ".0" << std::endl;
		return ;
	}
	classify_ntype(conv_info);
}
