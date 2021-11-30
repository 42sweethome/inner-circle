#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm& operator= (const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const & executor) const;
};

#endif
