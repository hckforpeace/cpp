#include "Harl.hpp"

int	main()
{
	// Harl *harl = new Harl();
	Harl harl = Harl();

	std::cout << "Harl complain level: debug" << std::endl;
	harl.complain("debug");
	std::cout << std::endl;

	std::cout << "Harl complain level: info" << std::endl;
	harl.complain("info");
	std::cout << std::endl;

	std::cout << "Harl complain level: warning" << std::endl;
	harl.complain("warning");
	std::cout << std::endl;

	std::cout << "Harl complain level: error" << std::endl;
	harl.complain("error");
	std::cout << std::endl;

	std::cout << "Harl complain level: Unknown" << std::endl;
	harl.complain("unknown");
	std::cout << std::endl;

	return (0);
}