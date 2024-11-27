#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>

class RPN
{
	private:
		std::string operation;
		std::stack<std::string> polstack;
	public:
		RPN(std::string operation);
		static void parse_input(std::string str);
		static bool is_number(std::string str);
		static bool is_operator(std::string str);
};

#endif