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
            cheolsoo.signForm(*scf);
            cheolsoo.executeForm(*scf);
        }
        if (rrf != 0)
        {
            cheolsoo.signForm(*rrf);
            cheolsoo.executeForm(*rrf);
        }
        if (ppf != 0)
        {
            cheolsoo.signForm(*ppf);
            cheolsoo.executeForm(*ppf);
        }
        if (wrong != 0)
        {
            cheolsoo.signForm(*wrong);
            cheolsoo.executeForm(*wrong);
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
