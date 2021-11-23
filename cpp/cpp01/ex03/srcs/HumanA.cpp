#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}

void HumanA::attack()
{
	std::cout << this->name << " is attacking with " << this->weapon.getType() << std::endl;
}
