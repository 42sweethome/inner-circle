#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class HighException : public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("Too High !!!");
        }
};

class LowException : public std::exception
{
    public:
        const char *what() const throw()
        {
            return("Too Low !!!");
        }
};

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat(const int grade);
        Bureaucrat& operator= (const Bureaucrat &src);
        ~Bureaucrat();
        
        HighException GradeTooHighException;
        LowException GradeTooLowException;
        std::string getName() const;
        int getGrade() const;
        void promotion();
        void promotion(int changetheworld);
        void demotion();
        void demotion(int changetheworld);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &src);

#endif