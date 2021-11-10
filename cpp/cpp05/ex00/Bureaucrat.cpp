#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("cheolsoo")
{
    grade = 150;
    std::cout << "Create Bureaucrat!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name("cheolsoo")
{
    *this = src;
}    

Bureaucrat::Bureaucrat(const int grade) : name("cheolsoo")
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Create Bureaucrat!" << std::endl;
}  

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        grade = src.getGrade();
        std::cout << "Create Bureaucrat!" << std::endl;
    }
    return (*this);
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
        throw GradeTooHighException();
    grade--;        
}

void Bureaucrat::promotion(int changetheworld)
{
    if (grade - changetheworld < 1)
        throw GradeTooHighException();
    grade -= changetheworld;
}

void Bureaucrat::demotion()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;  
}

void Bureaucrat::demotion(int changetheworld)
{
    if (grade + changetheworld > 150)
        throw GradeTooLowException();
    grade += changetheworld;
}