#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    Name = "noname";
    Hitpoints = FragTrap::Hitpoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
    this->Name = name;
    ClapTrap::Name = Name + "_clap_name";
    Hitpoints = FragTrap::Hitpoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap <" << Name << "> is called !"<< std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &src)
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

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap <" << Name << "> is uncalled !"<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ScavTrap(src), FragTrap(src)
{
	*this = src;
    std::cout << "DiamondTrap <" << Name << "> is copy called !"<< std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is <" << Name << ">"<< std::endl;
    std::cout << "ClapTrap name is <" << ClapTrap::Name << ">"<< std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
    ScavTrap::attack(target);
}
