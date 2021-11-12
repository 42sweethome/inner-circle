#include "../includes/Form.hpp"
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main()
{
    Form *scf;
    Form *rrf;
    Form *ppf;
    Form *wrong;
    std::cout << "test 1 ------------------" << std::endl;
    try
    {
        Intern someRandomIntern;

        scf = someRandomIntern.makeForm("shrubbery creation", "warrr_Mansion");
        rrf = someRandomIntern.makeForm("robotomy request", "robo");
        ppf = someRandomIntern.makeForm("presidential pardon", "cheolsoo");
        wrong = someRandomIntern.makeForm("Wrong case", "cheolsoo");

        Bureaucrat cheolsoo(2);
    
        if (scf != 0)
        {
            scf->beSigned(cheolsoo);
            scf->execute(cheolsoo);
        }
        if (rrf != 0)
        {
            rrf->beSigned(cheolsoo);
            rrf->execute(cheolsoo);
        }
        if (ppf != 0)
        {
            ppf->beSigned(cheolsoo);
            ppf->execute(cheolsoo);   
        }
        if (wrong != 0)
        {
            wrong->beSigned(cheolsoo);
            wrong->execute(cheolsoo);   
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    delete scf;
    delete rrf;
    delete ppf;
    delete wrong;
/*
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
    */
    return (0);
}