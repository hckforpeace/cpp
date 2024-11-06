#include "FileReplace.hpp"
#include <fstream>
#include <cstring>

FileReplace::FileReplace():filename(NULL), target(NULL), sub(NULL)
{
}


FileReplace::FileReplace(std::string filename, std::string target, std::string replace): filename(filename), target(target), sub(replace)
{
}

void	FileReplace::replace()
{
	std::string newfiles =  this->filename + ".replace";
	std::ifstream myfile(this->filename.c_str());
	std::string	line = "";
	char c;

	if (myfile.is_open())
	{
		std::ofstream newfile(newfiles.c_str());
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