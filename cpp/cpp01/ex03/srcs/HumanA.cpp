#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon.getType();
}

void HumanA::attack()
{
	std::cout << this->name << " is attacking with " << this->weapon << std::endl;
}
