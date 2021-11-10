#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class GradeTooHighException : public std::exception
{
    public:
        const char *what() const
        {
            return ("Too High !!!"); //?
        }
};

class GradeTooLowException : public std::exception
{
    public:
        const char *what() const
        {
            return("Too Low !!!"); //?
        }
};

class Bureaucrat
{
    private:
        const std::string name;
        int grade; //?
    public:
        //const int GradeTooHighException;
        //const int GradeTooLowException;
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat(const int grade);
        Bureaucrat& operator= (const Bureaucrat &src);
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;
        void promotion();
        void promotion(int changetheworld);
        void demotion();
        void demotion(int changetheworld);
};

#endif