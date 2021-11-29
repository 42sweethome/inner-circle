#include "../includes/Form.hpp"

int main()
{
    std::cout << "test 1 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 150);
        std::cout << std::endl;
        Form paper("zzanggoo", 120, 80);
        std::cout << std::endl;
        std::cout << paper;
        cheolsoo.promotion();
        cheolsoo.demotion();
        std::cout << std::endl;
        std::cout << "Now " << cheolsoo;
        std::cout << std::endl;
        cheolsoo.signForm(paper);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 2 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 100);
        std::cout << std::endl;
        Form paper("work", 120, 80);
        std::cout << std::endl;
        std::cout << paper;
        std::cout << std::endl;
        cheolsoo.promotion(50);
        cheolsoo.demotion(20);
        cheolsoo.promotion();
        cheolsoo.demotion();
        std::cout << std::endl;
        std::cout << "Now " << cheolsoo;
        std::cout << std::endl;
        cheolsoo.signForm(paper);
        std::cout << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 3 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 200);
        std::cout << std::endl;
        Form paper("work", 120, 80);
        std::cout << std::endl;
        std::cout << paper;
        std::cout << std::endl;
        cheolsoo.promotion(50);
        std::cout << std::endl;
        std::cout << "Now " << cheolsoo;
        std::cout << std::endl;
        cheolsoo.signForm(paper);
        std::cout << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 4 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 3);
        std::cout << std::endl;
        Form paper("work", 120, 80);
        std::cout << std::endl;
        std::cout << paper;
        cheolsoo.promotion(3);
        cheolsoo.demotion(200);
        std::cout << std::endl;
        std::cout << "Now " << cheolsoo;
        std::cout << std::endl;
        cheolsoo.signForm(paper);
        std::cout << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
