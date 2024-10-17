#include "Harl.hpp"

Harl::~Harl()
{
}

void Harl::filterComplain( std::string level )
{
	int	lvl = getComplainNnum(level);
	switch (lvl)
	{
		case 0:
			debug();
			info();
			warning();
			error();
			return ;
		case 1:
			info();
			warning();
			error();
			return ;
		case 2:
			warning();
			error();
			return ;
		case 3:
			error();
			return ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
}

int	Harl::getComplainNnum( std::string level )
{
	std::string levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return (-1);

}
void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}
void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}
