#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class HighException;
class LowException;
class Bureaucrat;

class Form
{
    private:
        const std::string name;
        const int signGrade;
        const int executeGrade;
        bool sign;
    public:
        Form();
        Form(const Form &src);
        Form(const int signGrade, const int executeGrade);
        Form& operator= (const Form &src);
        ~Form();

        HighException GradeTooHighException;
        LowException GradeTooLowException; // 변수앞에 *붙여주면 에러 해결????
        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getSign() const;
        void beSigned(const Bureaucrat &bur);
};

std::ostream& operator<<(std::ostream& os, const Form &src);

#endif