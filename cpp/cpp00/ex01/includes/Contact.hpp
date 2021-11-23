#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Contact
{
    private:
        std::string contact[5];
    
    public:
        Contact();
        void    add();
        void    output_phonebook();
        void    output_contact();
};

#endif