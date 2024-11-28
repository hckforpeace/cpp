#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::string operation;
		std::stack<std::string> polstack;
	public:
		RPN(std::string operation);
		void parse_input(std::string str);
		static bool is_number(std::string str);
		static bool is_operator(std::string str);
		static int	calculate(int first, int second, std::string a);
		void reverse_polish(std::string input);
};

#endif