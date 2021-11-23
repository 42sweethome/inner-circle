#include "../includes/Contact.hpp"

Contact::Contact()
{
    contact[0] = "";
    contact[1] = "";
    contact[2] = "";
    contact[3] = "";
    contact[4] = "";
}

void    navi_enter(int i)
{
    if (i == 0)
        std::cout << "first name : ";
    else if (i == 1)
        std::cout << "last name : ";
    else if (i == 2)
        std::cout << "nickname : ";
    else if (i == 3)
        std::cout << "phone number : ";
    else
        std::cout << "darkest secret : ";
}

void    Contact::add()
{
    int     i;

    i = -1;
    while (++i < 5)
    {
        navi_enter(i);
        std::getline(std::cin, contact[i]);
    }
}

void    Contact::output_phonebook()
{
    int     i;
    std::string tmp;

    i = -1;
    while (++i <= 2)
    {
        if (this->contact[i].length() >= 10)
        {
            tmp = this->contact[i].substr(0, 9);
            std::cout << tmp << '.';
        }
        else 
            std::cout << std::setw(10) << this->contact[i];
        if (i != 2)
            std::cout << '|';
    }
    std::cout << std::endl;
}

void    Contact::output_contact()
{
    int     i;

    i = -1;
    while (++i <= 4)
    {
        navi_enter(i);
        std::cout << contact[i] << std::endl;
    }
}