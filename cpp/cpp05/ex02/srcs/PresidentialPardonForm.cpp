#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Form", 25, 5, "cheolsoo")
{
    std::cout << "Create PresidentialPardonForm!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
    *this = src;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("Presidential Form", 25, 5, target)
{
    std::cout << "Create PresidentialPardonForm!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
        {
            std::cout << "Create PresidentialPardonForm!" << std::endl;
        }
        return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Delete PresidentialPardonForm!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (getSign() == false)
        throw NotSignedException;
    if (executor.getGrade() > getExecuteGrade())
        throw *GradeTooLowException;
    std::cout << "PresidentialForm : <" << getTarget() << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}
