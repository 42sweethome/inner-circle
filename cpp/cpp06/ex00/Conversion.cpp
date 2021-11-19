#include "Conversion.hpp"
#include <string>


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Put only one argument!" << std::endl;
		return (-1);
	}
	check_char(argv[1]);
	return (0);
}
