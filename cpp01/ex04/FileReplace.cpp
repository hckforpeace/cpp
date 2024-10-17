#include "FileReplace.hpp"
#include <fstream>
#include <cstring>

FileReplace::FileReplace(std::string filename, std::string target, std::string replace): filename(filename), target(target), sub(replace)
{
}

void	FileReplace::replace()
{
	std::ifstream myfile(this->filename);
	std::string	line = "";
	char c;

	if (myfile.is_open())
	{
		std::ofstream newfile(this->filename + ".replace");
		while (myfile)
		{
			c = myfile.get();
			if (myfile.tellg() > 0)
				line += c;
			if (line == this->target)
			{
				newfile << this->sub;
				line = "";
			}
			else if (myfile.tellg() < 0 || line.length() > this->target.length() || line != target.substr(0, line.length()))
			{
				newfile << line;
				line = "";
			}
		}
	}
	else
		std::cout << "file not valid" << std::endl;
}