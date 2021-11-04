#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();
        void whoAmI();
        void attack(std::string const & target)
        {
            ScavTrap::attack(target);
        }
};


#endif