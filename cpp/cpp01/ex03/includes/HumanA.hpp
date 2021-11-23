#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "../includes/Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
		
	public:
		HumanA(std::string name, Weapon &weapon);
		void attack();
};

#endif
