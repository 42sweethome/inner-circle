#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    Name = "noname";
    Hitpoints = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout << "ClapTrap <" << Name << "> is called !"<< std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    Hitpoints = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout << "ClapTrap <" << Name << "> is called !"<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
    std::cout << "ClapTrap <" << Name << "> is copy called !"<< std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap <" << Name << "> is uncalled !"<< std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		Name = src.Name;
        Hitpoints = src.Hitpoints;
        Energy_points = src.Energy_points;
        Attack_damage = src.Attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
     if (Energy_points == 0)
    {
        std::cout << "ClapTrap <" << Name \
        << "> has no Energy point !" <<std::endl;
    }
    else
    {
        Energy_points--;
        std::cout << "ClapTrap <" << Name \
        << "> attacks <" << target << ">" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > Hitpoints)
        Hitpoints = 0;
    else
        Hitpoints -= amount;
    std::cout << "ClapTrap <" << Name << "> causing <" << \
    amount << "> points of damage!" <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount + Hitpoints > 10)
        Hitpoints = 10;
    else
        Hitpoints += amount;
    std::cout << "ClapTrap <" << Name << "> is repaired <" << \
    amount << "> points of Hitpoints" <<std::endl;
}