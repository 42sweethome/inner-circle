	#include "Base.hpp"

	A::A()
	{
		std::cout << "create A" << std::endl;
	}

	A::A(const A &src)
	{
		*this = src;
		std::cout << "create copy A" << std::endl;
	}

	A& A::operator= (const A &src)
	{
		if (this != &src)
		{
			;
		}
		return (*this);
	}

	A::~A()
	{
		std::cout << "delete A" << std::endl;
	}

	B::B()
	{
		std::cout << "create B" << std::endl;
	}

	B::B(const B &src)
	{
		*this = src;
		std::cout << "create copy B" << std::endl;
	}

	B& B::operator= (const B &src)
	{
		if (this != &src)
		{
			;
		}
		return (*this);
	}

	B::~B()
	{
		std::cout << "delete B" << std::endl;
	}

	C::C()
	{
		std::cout << "create C" << std::endl;
	}

	C::C(const C &src)
	{
		*this = src;
		std::cout << "create copy C" << std::endl;
	}

	C& C::operator= (const C &src)
	{
		if (this != &src)
		{
			;
		}
		return (*this);
	}

	C::~C()
	{
		std::cout << "delete C" << std::endl;
	}

	Base::~Base()
	{

	}
