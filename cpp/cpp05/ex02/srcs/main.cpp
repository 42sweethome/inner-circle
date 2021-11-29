#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main()
{
    std::cout << "test 1 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 2);
		Bureaucrat zzanggoo("zzanggoo", 2);
        std::cout << std::endl;
        ShrubberyCreationForm sh("warrr_Mansion");
        std::cout << sh;
        PresidentialPardonForm pr("cheolsoo");
        std::cout << pr;
        RobotomyRequestForm ro("robo");
        std::cout << ro;
        std::cout << std::endl;

        zzanggoo.signForm(sh);
        cheolsoo.executeForm(sh);
        std::cout << std::endl;
		zzanggoo.signForm(ro);
        cheolsoo.executeForm(ro);
        std::cout << std::endl;
        zzanggoo.signForm(pr);
        cheolsoo.executeForm(pr);
        std::cout << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test 2 ------------------" << std::endl;
    try
    {
        Bureaucrat cheolsoo("cheolsoo", 140);
        Bureaucrat yuri("yuri", 55);
        Bureaucrat hoon("hoon", 15);
        std::cout << std::endl;
        ShrubberyCreationForm sh("warrr_Mansion");
        std::cout << sh;
        RobotomyRequestForm ro("robo");
        std::cout << ro;
        PresidentialPardonForm pr("hoon");
        std::cout << pr;
        std::cout << std::endl;

        try
        {
            cheolsoo.signForm(sh);
            cheolsoo.executeForm(sh);
            std::cout << std::endl;
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            yuri.signForm(ro);
            yuri.executeForm(ro);
            std::cout << std::endl;
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            hoon.signForm(pr);
            hoon.executeForm(pr);
            std::cout << std::endl;
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
