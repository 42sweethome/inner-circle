#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
    private:
        Contact contact[8];
        void        output_phonebook(int i);
        void        output_contact(int i);

    public:
        void        add(int i);
        void        show_contacts(int cnt, int flag);
};

#endif