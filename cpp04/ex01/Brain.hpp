#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		// Canoncical Form
		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain&	operator=(const Brain &copy);
};

#endif