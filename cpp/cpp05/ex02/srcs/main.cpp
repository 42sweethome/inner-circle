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
		Bureaucrat zzanggoo(2);
        ShrubberyCreationForm sh("warrr_Mansion");
        PresidentialPardonForm pr("cheolsoo");
        RobotomyRequestForm ro("robo");

        zzanggoo.signForm(sh);
        cheolsoo.executeForm(sh);
		zzanggoo.signForm(ro);
        cheolsoo.executeForm(ro);
        zzanggoo.signForm(pr);
        cheolsoo.executeForm(pr);
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
            cheolsoo.signForm(sh);
            cheolsoo.executeForm(sh);
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            yuri.signForm(ro);
            yuri.executeForm(ro);
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            hoon.signForm(pr);
            hoon.executeForm(pr);
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
