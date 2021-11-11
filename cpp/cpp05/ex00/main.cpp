#include "Bureaucrat.hpp"

int main()
{
    std::cout << "test 1 ------------------" << std::endl;
    try
    {
        Bureaucrat a(150);
        a.promotion();
        a.demotion();
        std::cout << "Now " << a;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 2 ------------------" << std::endl;
    try
    {
        Bureaucrat a(100);
        a.promotion(50);
        a.demotion(20);
        a.promotion();
        a.demotion();
        std::cout << "Now " << a;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 3 ------------------" << std::endl;
    try
    {
        Bureaucrat a(200);
        a.promotion(50);
        std::cout << "Now " << a;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 4 ------------------" << std::endl;
    try
    {
        Bureaucrat a(3);
        a.promotion(3);
        a.demotion(200);
        std::cout << "Now " << a;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}