#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        virtual ~ScavTrap();

        ScavTrap & operator=(const ScavTrap &src);
        virtual void attack(std::string const & target);
        void guardGate();
};

#endif
