#include "../includes/Form.hpp"

Form::Form() : name("paper"), signGrade(120), executeGrade(80), target("")
{
    sign = false;
    std::cout << "Create Form!" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade, std::string target) : name(name), signGrade(signGrade), executeGrade(executeGrade), target(target)
{
	if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException;
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException;
    sign = false;
    std::cout << "Create Form!" << std::endl;
}

Form::Form(const Form &src) : name(src.getName()), signGrade(src.signGrade), executeGrade(src.getExecuteGrade()), target(src.getTarget())
{
    std::cout << "Create Copy Form!" << std::endl;
    *this = src;
}

Form& Form::operator=(const Form &src)
{
    if (this != &src)
        sign = src.sign;
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form &src)
{
    os << "<" << src.getName() << \
    ">, signGrade <" << src.getSignGrade() << \
    ">, executeGrade <" << src.getExecuteGrade() << \
    ">, sign <" << src.getSign() << \
    ">" << std::endl;
    return (os);
}

Form::~Form()
{
    std::cout << "Delete Form!" << std::endl;
}

std::string Form::getName() const
{
    return (name);
}

int Form::getSignGrade() const
{
    return (signGrade);
}

int Form::getExecuteGrade() const
{
    return (executeGrade);
}

bool Form::getSign() const
{
    return (sign);
}

std::string Form::getTarget() const
{
    return (target);
}

void Form::beSigned(const Bureaucrat &bur)
{
    if (getSignGrade() < bur.getGrade())
    {
        sign = false;
        throw *GradeTooLowException;
    }
    sign = true;
}

const char *IsSignedException::what() const throw()
{
	return ("Not signed");
}
