#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a(200);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << "??" << std::endl;
    }
}