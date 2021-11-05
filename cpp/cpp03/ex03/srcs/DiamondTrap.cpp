#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    Name = "noname";
    Hitpoints = FragTrap::Hitpoints;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap <" << Name << "> is called !"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) 
{
    this->Name = name;
    ClapTrap::Name = name + "_clap_name";
    Hitpoints = FragTrap::Hitpoints;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap <" << Name << "> is called !"<< std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &src)
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

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap <" << Name << "> is uncalled !"<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is <" << Name << ">"<< std::endl;
    std::cout << "ClapTrap name is <" << ClapTrap::Name << ">"<< std::endl;
}