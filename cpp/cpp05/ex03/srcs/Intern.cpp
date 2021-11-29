#include "../includes/Intern.hpp"

Intern::Intern()
{
    std::cout << "Create Intern!" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Create Copy Intern!" << std::endl;
    *this = src;
}

Intern& Intern::operator=(const Intern &src)
{
    if (this != &src)
    	;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Delete Intern!" << std::endl;
}

Form *Intern::makeForm(std::string form, std::string target) const
{
    Form *ret;
    int idx;
	std::string	arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	idx = -1;
	while (++idx < 3 && form.compare(arr[idx]))
		;
	switch (idx)
	{
		case 0:
            std::cout << "Intern creates <" << form << ">" << std::endl;
			ret = new ShrubberyCreationForm(target);
			break;
		case 1:
            std::cout << "Intern creates <" << form << ">" << std::endl;
			ret = new RobotomyRequestForm(target);
			break;
		case 2:
            std::cout << "Intern creates <" << form << ">" << std::endl;
			ret = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Form doesn't exist." << std::endl;
			return (0);
	}
    return (ret);
}
