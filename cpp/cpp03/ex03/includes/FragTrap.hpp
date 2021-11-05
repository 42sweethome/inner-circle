#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        ~FragTrap();

        FragTrap & operator=(const FragTrap &src);

        void highFiveGuys();
};


#endif