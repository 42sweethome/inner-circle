#include "../includes/Form.hpp"

int main()
{
    std::cout << "test 1 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo(150);
        Form paper(120, 80);
        std::cout << paper;
        cheolsoo.promotion();
        cheolsoo.demotion();
        std::cout << "Now " << cheolsoo;
        try
        {
            paper.beSigned(cheolsoo);
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        cheolsoo.signForm(paper);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 2 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo(100);
        Form paper(120, 80);
        std::cout << paper;
        cheolsoo.promotion(50);
        cheolsoo.demotion(20);
        cheolsoo.promotion();
        cheolsoo.demotion();
        std::cout << "Now " << cheolsoo;
        try
        {
            paper.beSigned(cheolsoo);
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        cheolsoo.signForm(paper);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 3 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo(200);
        Form paper(120, 80);
        std::cout << paper;
        cheolsoo.promotion(50);
        std::cout << "Now " << cheolsoo;
        try
        {
            paper.beSigned(cheolsoo);
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        cheolsoo.signForm(paper);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 4 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo(3);
        Form paper(120, 80);
        std::cout << paper;
        cheolsoo.promotion(3);
        cheolsoo.demotion(200);
        std::cout << "Now " << cheolsoo;
        try
        {
            paper.beSigned(cheolsoo);
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        cheolsoo.signForm(paper);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}