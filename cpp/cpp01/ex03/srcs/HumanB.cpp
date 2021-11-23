#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << this->name << " is attacking with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " is attacking with hand" << std::endl;
}
