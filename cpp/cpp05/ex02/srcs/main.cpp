#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main()
{
    std::cout << "test 1 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo(2);
        ShrubberyCreationForm sh("warrr_Mansion");
        PresidentialPardonForm pr("cheolsoo");
        RobotomyRequestForm ro("robo");
    
        sh.beSigned(cheolsoo);
        sh.execute(cheolsoo);
        ro.beSigned(cheolsoo);
        ro.execute(cheolsoo);
        pr.beSigned(cheolsoo);
        pr.execute(cheolsoo);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 2 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo(140);
        Bureaucrat yuri(55);
        Bureaucrat hoon(15);
        ShrubberyCreationForm sh("warrr_Mansion");
        RobotomyRequestForm ro("robo");
        PresidentialPardonForm pr("hoon");

        try
        {
            sh.beSigned(cheolsoo);
            sh.execute(cheolsoo);
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            ro.beSigned(yuri);
            ro.execute(yuri);
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            pr.beSigned(hoon);
            pr.execute(hoon);
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}