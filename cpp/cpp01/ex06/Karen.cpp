#include "Karen.hpp"

Karen::Karen(void)
{

}

Karen::~Karen(void)
{

}

void Karen::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl << "I love to get extra bacon \
for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
}

void Karen::info( void )
{
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra \
bacon cost more money. You don’t put enough! If you did I would not have to ask \
for it!" << std::endl << std::endl;
}

void Karen::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been \
coming here for years and you just started working here last month." << std::endl << std::endl;
}

void Karen::error( void )
{
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable, I want to speak to the manager now." \
	<< std::endl << std::endl;
}

void Karen::complain( std::string level )
{
	int idx;
	std::string	arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Karen::*fp[4])(void);

	fp[0] = &Karen::debug;
	fp[1] = &Karen::info;
	fp[2] = &Karen::warning;
	fp[3] = &Karen::error;

	idx = -1;
	while (++idx < 4 && level.compare(arr[idx]))
		;
	switch (idx)
	{
		case 0:
			(this->*fp[0])();
		case 1:
			(this->*fp[1])();
		case 2:
			(this->*fp[2])();
		case 3:
			(this->*fp[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
			break ;
	}
}