#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
    std::string Name;
    unsigned int Hitpoints;
    unsigned int Energy_points;
    unsigned int Attack_damage;
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();
    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif