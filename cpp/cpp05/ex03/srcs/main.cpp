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
        std::cout << std::endl;
        scf = someRandomIntern.makeForm("shrubbery creation", "warrr_Mansion");
        std::cout << *scf;
        rrf = someRandomIntern.makeForm("robotomy request", "robo");
        std::cout << *rrf;
        ppf = someRandomIntern.makeForm("presidential pardon", "cheolsoo");
        std::cout << *ppf;
        wrong = someRandomIntern.makeForm("Wrong case", "cheolsoo");
        std::cout << std::endl;
        Bureaucrat cheolsoo("cheolsoo", 2);
        std::cout << cheolsoo;
        std::cout << std::endl;
        if (scf != 0)
        {
            cheolsoo.signForm(*scf);
            cheolsoo.executeForm(*scf);
            std::cout << std::endl;
        }
        if (rrf != 0)
        {
            cheolsoo.signForm(*rrf);
            cheolsoo.executeForm(*rrf);
            std::cout << std::endl;
        }
        if (ppf != 0)
        {
            cheolsoo.signForm(*ppf);
            cheolsoo.executeForm(*ppf);
            std::cout << std::endl;
        }
        if (wrong != 0)
        {
            cheolsoo.signForm(*wrong);
            cheolsoo.executeForm(*wrong);
            std::cout << std::endl;
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
    return (0);
}
