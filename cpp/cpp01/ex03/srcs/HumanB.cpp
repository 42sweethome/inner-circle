#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon.getType();
}

void HumanB::attack()
{
	std::cout << this->name << " is attacking with " << this->weapon << std::endl;
}
