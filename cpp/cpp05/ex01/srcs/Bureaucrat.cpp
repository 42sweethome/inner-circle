#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("cheolsoo")
{
    grade = 150;
    std::cout << "Create Bureaucrat!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name("cheolsoo")
{
    std::cout << "Create Bureaucrat!" << std::endl;
    *this = src;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException;
    else if (grade > 150)
        throw GradeTooLowException;
    this->grade = grade;
    std::cout << "Create Bureaucrat!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
        grade = src.getGrade();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &src)
{
    os << "<" << src.getName() << ">, bureaucrat grade <" << src.getGrade() << ">" << std::endl;
    return (os);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Delete Bureaucrat!" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

std::string Bureaucrat::getName() const
{
    return (name);
}

void Bureaucrat::promotion()
{
    if (grade - 1 < 1)
        throw GradeTooHighException;
    grade--;
    std::cout << *this;
}

void Bureaucrat::promotion(int changetheworld)
{
    if (grade - changetheworld < 1)
        throw GradeTooHighException;
    grade -= changetheworld;
    std::cout << *this ;
}

void Bureaucrat::demotion()
{
    if (grade + 1 > 150)
        throw GradeTooLowException;
    grade++;
    std::cout << *this ;
}

void Bureaucrat::demotion(int changetheworld)
{
    if (grade + changetheworld > 150)
        throw GradeTooLowException;
    grade += changetheworld;
    std::cout << *this ;
}

void Bureaucrat::signForm(Form &src)
{
    try
    {
        src.beSigned(*this);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    if (src.getSign() == true)
    {
        std::cout << "<" << getName() << \
        "> sign <" << src.getName() << \
        ">" << std::endl;
    }
    else
    {
        std::cout << "<" << getName() << \
        "> cannot sign <" << src.getName() << \
        "> because <Too Low !!!>" << std::endl;
    }
}

const char *HighException::what() const throw()
{
    return ("Too High !!!");
}

const char *LowException::what() const throw()
{
    return("Too Low !!!");
}