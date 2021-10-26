#include "PhoneBook.hpp"
class Phonebook
{
    private:
    char *first;
    char *last;
    char *nick;
    char *num;
    char *secret;
    public:
    Phonebook();
//    void exit();
    void add();
//    void search();
};
/*
Phonebook::Phonebook()
{
    first = 0;
    last = 0;
    nick = 0;
    num = 0;
    secret = 0;
}*/
// void    Phonebook::exit()
// {
// }
void    Phonebook::add()
{
    std::string info;
    std::cout << "first name : ";
    std::getline(std::cin, info);
    first = new char[info.length() + 1];
    info.copy(first, info.length(), 0);
    first[info.length()] = '\0';
    
    std::cout << "last name : ";
    std::getline(std::cin, info);
    last = new char[info.length() + 1];
    info.copy(last, info.length(), 0);
    last[info.length()] = '\0';

    std::cout << "nickname : ";
    std::getline(std::cin, info);
    nick = new char[info.length() + 1];
    info.copy(nick, info.length(), 0);
    nick[info.length()] = '\0';

    std::cout << "phone number : ";
    std::getline(std::cin, info);
    num = new char[info.length() + 1];
    info.copy(num, info.length(), 0);
    num[info.length()] = '\0';

    std::cout << "darkest secret : ";
    std::getline(std::cin, info);
    secret = new char[info.length() + 1];
    info.copy(secret, info.length(), 0);
    secret[info.length()] = '\0';
}
// Phonebook::~Phonebook()
// {
// }
int main(void)
{
    Phonebook phonebook[8]; // this????
    std::string str;
    int i;
    i = -1;
    while (42)
    {
        std::cout << "Enter a command(ADD or SEARCH or EXIT) : ";
        std::getline(std::cin, str);
        if (str.compare("ADD") == 0)
        {
//            phonebook[++i] = new Phonebook();
            phonebook[i].add();
        }
    /*  else if (str.compare("SEARCH") == 0)
        else if (str.compare("EXIT") == 0)
        {
            break ;
        }*/
        else
            std::cout << "WRONG!" << std::endl;
    }
    return (0);
}