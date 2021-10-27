#include "PhoneBook.hpp"
class Phonebook
{
    private:
    std::string contact[5];

    public:
    Phonebook();
    void add();
    void    output_phonebook();
    void    output_contact();
    static void show_contacts(Phonebook *phonebook[8], int cnt, int flag);
    static void destruct(Phonebook *phonebook[8], int cnt, int flag);
};

Phonebook::Phonebook()
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

void    Phonebook::add()
{
    int     i;

    i = -1;
    while (++i < 5)
    {
        navi_enter(i);
        std::getline(std::cin, contact[i]);
    }
}

void    Phonebook::output_phonebook()
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

void    Phonebook::output_contact()
{
    int     i;

    i = -1;
    while (++i <= 4)
    {
        navi_enter(i);
        std::cout << contact[i] << std::endl;
    }
}

void    Phonebook::show_contacts(Phonebook *phonebook[8], int cnt, int flag)
{
    int     i;
    std::string answer;

    if (flag == 1)
        cnt = 7;
    i = -1;
    while (++i <= cnt)
    {
        std::cout << std::setw(10) << i << '|';
        phonebook[i]->output_phonebook();
    }
    std::cout << "What are you looking for? : ";
    std::getline(std::cin, answer);
	std::stringstream ssInt(answer);
	ssInt >> i;
    if (0 <= i && i <= cnt)
        phonebook[i]->output_contact();
    else
        std::cout << "You've entered a wrong number!" << std::endl;
}

void Phonebook::destruct(Phonebook *phonebook[8], int cnt, int flag)
{
    int     i;
    if (flag == 1)
        cnt = 7;
    i = -1;
    while (++i <= cnt)
        delete phonebook[i];
}

int main(void)
{
    Phonebook *phonebook[8];
    std::string str;
    int     i;
    int     flag;

    i = -1;
    flag = 0;
    while (42)
    {
        std::cout << "Enter a command(ADD or SEARCH or EXIT) : ";
        std::getline(std::cin, str);
        if (str.compare("ADD") == 0)
        {
            i++;
            if (flag == 0)
                phonebook[i] = new Phonebook();
            phonebook[i]->add();
            if (i == 7)
            {
                i = -1;
                flag = 1;
            }
        }
        else if (str.compare("SEARCH") == 0)
        {
            Phonebook::show_contacts(phonebook, i, flag);
        }
        else if (str.compare("EXIT") == 0)
        {
            break ;
        }
        else
        {
            std::cout << "WRONG!" << std::endl;
        }
    }
    Phonebook::destruct(phonebook, i, flag);
    return (0);
}