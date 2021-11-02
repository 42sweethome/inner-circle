#include "Karen.hpp"

int     main(int argc, char **argv)
{
    Karen   karen;

    if (argc != 2)
    {
        std::cout << "What do you want for me..?" << std::endl;
        return (-1);
    }
    karen.complain(static_cast<std::string>(argv[1]));
    return (0);
}