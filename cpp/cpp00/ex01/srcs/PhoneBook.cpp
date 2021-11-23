#include "../includes/PhoneBook.hpp"

void    Phonebook::add(int i)
{
    contact[i].add();
}

void    Phonebook::output_phonebook(int i)
{
    contact[i].output_phonebook();
}

void    Phonebook::output_contact(int i)
{
    contact[i].output_contact();
}

void    Phonebook::show_contacts(int cnt, int flag)
{
    int     i;
    std::string answer;

    if (flag == 1)
        cnt = 7;
    i = -1;
    while (++i <= cnt)
    {
        std::cout << std::setw(10) << i << '|';
        output_phonebook(i);
    }
    std::cout << "What are you looking for? : ";
    std::getline(std::cin, answer);
	std::stringstream ssInt(answer);
	ssInt >> i;
    if (answer.find_first_not_of("0123456789") == std::string::npos && 0 <= i && i <= cnt)
        output_contact(i);
    else
        std::cout << "You've entered a wrong number!" << std::endl;
}

int main(void)
{
    Phonebook phonebook;
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
            phonebook.add(i);
            if (i == 7)
            {
                flag = 1;
                i = -1;
            }
        }
        else if (str.compare("SEARCH") == 0)
        {
            phonebook.show_contacts(i, flag);
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
    return (0);
}