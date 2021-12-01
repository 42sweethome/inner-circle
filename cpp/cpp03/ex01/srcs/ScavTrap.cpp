#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    Name = "noname";
    Hitpoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap <" << Name << "> is called !"<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    Hitpoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap <" << Name << "> is called !"<< std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		Name = src.Name;
        Hitpoints = src.Hitpoints;
        EnergyPoints = src.EnergyPoints;
        AttackDamage = src.AttackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap <" << Name << "> is uncalled !"<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
    std::cout << "ScavTrap <" << Name << "> is copy called !"<< std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap <" << Name << "> is in guardGate mode !"<< std::endl;
}

void ScavTrap::attack(std::string const & target)
{
    if (EnergyPoints == 0)
    {
        std::cout << "ScavTrap <" << Name \
        << "> has no Energy point !" <<std::endl;
    }
    else
    {
        EnergyPoints--;
        std::cout << "ScavTrap <" << Name \
        << "> attacks <" << target << ">" << std::endl;
    }
}
