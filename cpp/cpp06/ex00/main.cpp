# include "Conversion.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Put only one argument!" << std::endl;
		return (-1);
	}
	Conversion conversion(argv[1]);
	conversion.check_param();
	return (0);
}

