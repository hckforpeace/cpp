#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# define ASCII_TREE     "   oxoxoo    ooxoo\n"\
"  ooxoxo oo  oxoxooo\n"\
" oooo xxoxoo ooo ooox\n"\
" oxo o oxoxo  xoxxoxo\n"\
"  oxo xooxoooo o ooo\n"\
"    ooooooo  /o/o\n"\
"        \\  / /\n"\
"         |   /\n"\
"         |  |\n"\
"         | D|\n"\
"         |  |\n"\
"         |  |\n"\
"  ______/____\\____\n"\

# define SHRU_EXECGRADE 137
# define SHRU_SIGNGRADE 145
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
	public:
		// Constructors
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		// overload = operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);

		// Public methods
		std::string	getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

// std::ostream&	operator<<(std::ostream& stream, ShrubberyCreationForm& sh);

#endif