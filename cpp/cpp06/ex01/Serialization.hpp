#include <iostream>
//#include <fstream>
//#include <string>

struct Data
{
	short id;
	int age;
	double wage;
	std::string name;
	char *test;
};

class Serialize
{
	private:
		Data dt;
	public:
		Serialize();
		Serialize(const Serialize &src);
        Serialize& operator= (const Serialize &src);
        ~Serialize();

		void dt_show();
		Data *getValue();
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
