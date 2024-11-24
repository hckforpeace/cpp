#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange()
{

}


BitcoinExchange::BitcoinExchange()
{
}


BitcoinExchange::BitcoinExchange(std::string inputFile): _inputFile(inputFile)
{
	// this->infile_stream.open(this->_inputFile.c_str(), std::ios::in);
	// if (this->infile_stream.is_open())
	// {
		this->loadDb();
	// }
	// else
	// {
		// std::cerr << "ICI" << std::endl;
		// throw (BitcoinExchange::BadInputException());
	// }	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this == &src)
		return (*this);
	this->_inputFile = src._inputFile;
	this->_db = src._db;
	return (*this);
}



/* ************************************************************************** */
/*                                 Exceptions                                 */
/* ************************************************************************** */

const char * BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return ("could not open file");
}

const char * BitcoinExchange::NotAPositiveNumberException::what() const throw()
{
	return ("not a positive number.");
}

const char * BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return ("too large a number.");
}

const char * BitcoinExchange::BadInputException::what(unsigned int line) const throw()
{
	return ("bad input at line " + line);
}

/* ************************************************************************** */
/*                             Private Member Functions                       */
/* ************************************************************************** */

void	BitcoinExchange::loadDb( void )
{
	std::ifstream database;
	database.open(DB_NAME, std::ios::in);
	std::string line;
	if (database.is_open())
	{
		std::getline(database, line);		
		while (std::getline(database, line))
		{
			this->parse_save_line(line);
		}
	}
	else
		throw BitcoinExchange::CouldNotOpenFileException();
}

/* ************************************************************************** */
/*                           	  Getter                             	      */
/* ************************************************************************** */

std::map<std::string, std::string>& BitcoinExchange::getMap( void )
{
	return (this->_db);
}

/* ************************************************************************** */
/*                             Static Member Function                         */
/* ************************************************************************** */

void BitcoinExchange::parse_save_line( std::string line)
{
	int sepIdx = line.find(',');
	if (line.find(',') == std::string::npos)
		throw std::runtime_error("bas line in db file");
	this->_db.insert(std::pair<std::string, std::string>(line.substr(0, sepIdx), line.substr(sepIdx + 1)));
}


/* ************************************************************************** */
/*                             Public member functions                        */
/* ************************************************************************** */

void	BitcoinExchange::displayDB( void )
{
	for (std::map<std::string, std::string>::iterator it = this->_db.begin(); it != this->_db.end(); it++)
		std::cout << "date: " << it->first << " exchange rate: " << it->second << std::endl;
}