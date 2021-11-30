#include "Base.hpp"

Base * generate(void)
{
	int random;
	Base *type;

	srand(static_cast<unsigned int>(time(NULL)));
	random = rand() % 3;
	if (random == 0)
		type = new A;
	else if (random == 1)
		type = new B;
	else
		type = new C;
	return (type);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	Base ref;
	try
	{
		ref = dynamic_cast<A&>(p);
		std::cout << "&A" << std::endl;
	}
	catch (...)
	{

	}
	try
	{
		ref = dynamic_cast<B&>(p);
		std::cout << "&B" << std::endl;
	}
	catch(...)
	{

	}
	try
	{
		ref = dynamic_cast<C&>(p);
		std::cout << "&C" << std::endl;
	}
	catch(...)
	{

	}
}

int	main()
{
	Base *p;

	p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}
