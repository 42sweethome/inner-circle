#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Form", 72, 45, "Robo")
{
    std::cout << "Create RobotomyRequestForm!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
    *this = src;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("Robotomy Form", 72, 45, target)
{
    std::cout << "Create RobotomyRequestForm!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
        {
            std::cout << "Create RobotomyRequestForm!" << std::endl;
        }
        return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Delete RobotomyRequestForm!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (getSign() == false)
        throw NotSignedException;
    if (executor.getGrade() > getExecuteGrade())
        throw *GradeTooLowException;
    std::cout << "RobotomyForm : bzzzzzzzz..." << std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
    if (rand() % 2 == 0)
        std::cout << "RobotomyForm : <" << getTarget() << "> has been failed to be robotomized." << std::endl;
    else
        std::cout << "RobotomyForm : <" << getTarget() << "> has been robotomized successfully." << std::endl;

}
