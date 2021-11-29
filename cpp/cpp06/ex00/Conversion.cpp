#include "Conversion.hpp"

Conversion::Conversion()
{
	sign = 0;
	point = 0;
	isfloat = 0;
	pseudo = 0;
	isstring = 0;
	ischar = 0;
	isprint = 0;
	f_zero = 0;
	d_zero = 0;
	*this->argv = 0;
}

Conversion::Conversion(char *argv)
{
	sign = 0;
	point = 0;
	isfloat = 0;
	pseudo = 0;
	isstring = 0;
	ischar = 0;
	isprint = 0;
	f_zero = 0;
	d_zero = 0;
	this->argv = argv;
}

Conversion::Conversion(const Conversion &src)
{
    *this = src;
}

Conversion& Conversion::operator=(const Conversion &src)
{
    if (this != &src)
    {
		sign = src.sign;
		point = src.point;
		isfloat = src.isfloat;
		pseudo = src.pseudo;
		isstring = src.isstring;
		ischar = src.ischar;
		isprint = src.isprint;
		f_zero = src.f_zero;
		d_zero = src.d_zero;
		this->argv = src.argv;
	}
    return (*this);
}

Conversion::~Conversion()
{
}

void Conversion::check_param()
{
	int i;
	int ret;
	
	ret = 1;
	i = -1;
	while (argv[++i])
	{
		ret = check_num(i);
		if (!ret)
		{
			ret = get_num_info(i);
			if (ret)
				break ;
		}
		else
			break ;
	}
	if (ret && argv[0])
		check_string();
	else
		check_isprint();
	classify_type();
	return ;
}

int Conversion::check_num(int i)
{
	if (argv[i] == '+' || argv[i] == '-' || argv[i] == '.' \
	|| argv[i] == 'f' || (argv[i] >= '0' && argv[i] <= '9'))
		return (0);
	else
		return (1);
}

int Conversion::get_num_info(int idx)
{
	if (argv[idx] == '+' || argv[idx] == '-')
	{
		if (idx == 0)
			sign = 1;
		else
			return (1);
	}
	else if (argv[idx] == '.')
	{
		if ((sign && idx == 1) || idx == 0 \
		|| point || argv[idx + 1] == 0 \
		|| argv[idx + 1] == 'f')
			return (1);
		point = idx - sign;
	}
	else if (argv[idx] == 'f')
	{
		if (argv[idx + 1] != 0 || point == 0)
			return (1);
		isfloat = 1;
	}
	return (0);
}

int Conversion::ft_strlen()
{
	int i;
	
	i = -1;
	while (argv[++i])
		;
	return (i);
}

void Conversion::check_isprint()
{
	double d_tmp = 0;
	float f_tmp = 0;

	if (point <= 6)
		f_tmp = pow(0.1, 6 - point);
	if (point <= 15)
		d_tmp = pow(0.1, 15 - point);
	dounum = strtod(argv, NULL);
	fnum = strtof(argv, NULL);
	if (round(abs(dounum - atoi(argv)) * pow(10, 15 - point))\
						/ pow(10, 15 - point) <= d_tmp)
		d_zero = 1;
	if (round(abs(fnum - atoi(argv)) * pow(10, 6 - point))\
						/ pow(10, 6 - point) <= f_tmp)
		f_zero = 1;
	if ((dounum > -1 && dounum < 32) \
	|| dounum == 127)
		isprint = 1;
}

int Conversion::check_pseudo()
{
	std::string pseudo;

	pseudo = static_cast<std::string> (argv);
	if (!pseudo.compare("-inff") || !pseudo.compare("+inff") \
		||!pseudo.compare("nanf") || !pseudo.compare("inff"))
	{
		(argv)[(ft_strlen() - 1)] = 0;
		return (1);
	}
	else if (!pseudo.compare("-inf") || !pseudo.compare("+inf") \
		||!pseudo.compare("inf") || !pseudo.compare("nan"))
		return (1);
	return (0);
}

void Conversion::check_string()
{
	if (argv[0] != 0 && argv[1] != 0)
	{
		if (check_pseudo())
			pseudo = 1;
		else
			isstring = 1;
	}
	else
		ischar = 1;
}

void Conversion::classify_ntype()
{
	if (isprint)
		std::cout << "char: Non displayable" << std::endl;
	else if (dounum < 0 || dounum > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char> (dounum) << std::endl;
	if (dounum > INT_MAX || dounum < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int> (dounum) << std::endl;
	std::cout << "float: " << fnum;
	if ((f_zero && point <= 6))
		std::cout << ".0f"<< std::endl;
	else
		std::cout << "f"<< std::endl;
	std::cout << std::setprecision(15);
	std::cout << "double: " << dounum;
	if (d_zero && point <= 15)
		std::cout << ".0"<< std::endl;
	else
		std::cout << std::endl;
}

void Conversion::classify_type()
{
	if (pseudo)
	{
		if (argv[0] == '+')
			argv++;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << argv << "f" << std::endl;
		std::cout << "double: " << argv << std::endl;
		return ;
	}
	else if (isstring)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	else if (ischar)
	{
		std::cout << "char: " << argv[0] << std::endl;
		std::cout << "int: " << static_cast<int> (argv[0]) <<std::endl;
		std::cout << "float: " << static_cast<float> (argv[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double> (argv[0]) << ".0" << std::endl;
		return ;
	}
	classify_ntype();
}
