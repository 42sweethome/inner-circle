#include "Bureaucrat.hpp"

int main()
{
    std::cout << "test 1 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 150);
        cheolsoo.promotion();
        cheolsoo.demotion();
        std::cout << "Now " << cheolsoo;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 2 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 100);
        cheolsoo.promotion(50);
        cheolsoo.demotion(20);
        cheolsoo.promotion();
        cheolsoo.demotion();
        std::cout << "Now " << cheolsoo;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 3 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 200);
        cheolsoo.promotion(50);
        std::cout << "Now " << cheolsoo;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 4 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 3);
        cheolsoo.promotion(3);
        cheolsoo.demotion(200);
        std::cout << "Now " << cheolsoo;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}