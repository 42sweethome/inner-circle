#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class HighException;
class LowException;
class Bureaucrat;

class IsSignedException : public std::exception
{
    public:
        const char *what() const throw();
};

class Form
{
    private:
        const std::string name;
        const int signGrade;
        const int executeGrade;
        bool sign;
        std::string target;

    public:
        Form();
        Form(const Form &src);
        Form(const int signGrade, const int executeGrade);
        Form(std::string name, int signGrade, int executeGrade, std::string target);
        Form& operator= (const Form &src);
        virtual ~Form();

        HighException *GradeTooHighException;
        LowException *GradeTooLowException;
        IsSignedException NotSignedException;
        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getSign() const;
        std::string getTarget() const;
        void beSigned(const Bureaucrat &bur);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Form &src);

#endif
