#include "Serialization.hpp"

Serialize::Serialize()
{
	dt.id = 1;
	dt.age = 10;
	dt.wage = 100;
	dt.name = "cheolsoo";
    std::cout << "Create Serialize!" << std::endl;
}

Serialize::Serialize(const Serialize &src)
{
	std::cout << "Create Copy Serialize!" << std::endl;
    *this = src;
}

Serialize& Serialize::operator=(const Serialize &src)
{
    if (this != &src)
	{
    	dt.id = src.dt.id;
		dt.age = src.dt.age;
		dt.wage = src.dt.wage;
		dt.name = src.dt.name;
	}
    return (*this);
}

Serialize::~Serialize()
{
    std::cout << "Delete Serialize!" << std::endl;
}

void Serialize::dt_show()
{
	std::cout << "dt   :" << &(dt) << std::endl;
	std::cout << "id   :" << &(dt.id) << std::endl;
	std::cout << "age  :" << &(dt.age) << std::endl;
	std::cout << "wage :" << &(dt.wage) << std::endl;
	std::cout << "name :" << &(dt.name) << std::endl;
}

Data *Serialize::getValue()
{
	return (&dt);
}
