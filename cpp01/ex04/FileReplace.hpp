#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <iostream>

class FileReplace{
	public:
		FileReplace(std::string filename, std::string target, std::string replace);
		void	replace();

	private:
		std::string filename;
		std::string target;
		std::string sub;
};

#endif