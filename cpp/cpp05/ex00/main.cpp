#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a(200); // operator << 해야함
        a.promotion(150);
        a.demotion(50);
        a.promotion();
        a.demotion();
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}