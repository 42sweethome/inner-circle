#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string Name;
    unsigned int Hitpoints;
    unsigned int Energy_points;
    unsigned int Attack_damage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &src);
    ~ClapTrap();

    ClapTrap & operator=(const ClapTrap &src);

    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif