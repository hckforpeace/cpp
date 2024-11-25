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

const char * BitcoinExchange::BadInputException::what() const throw()
{
	std::stringstream str;
	str << line;
	static std::string ret = "Wrong input at line " + str.str();
	return (ret.c_str());
	// str << 
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
		if (line.compare("date,exchange_rate"))
			throw BitcoinExchange::BadInputException(0);
		int fline = 1;
		while (std::getline(database, line))
		{
			this->save_line(line, fline);
			fline++;
		}
		parse_db();
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
/*                             Private Member Function                         */
/* ************************************************************************** */



/* ************************************************************************** */
/*                             Public member functions                        */
/* ************************************************************************** */

void	BitcoinExchange::displayDB( void )
{
	for (std::map<std::string, std::string>::iterator it = this->_db.begin(); it != this->_db.end(); it++)
		std::cout << "date: " << it->first << " exchange rate: " << it->second << std::endl;
}

void BitcoinExchange::save_line(std::string line, int fline)
{
	int sepIdx = line.find(',');
	if (line.empty() || line.find(',') == std::string::npos)
		throw BitcoinExchange::BadInputException(fline);
	else
		this->_db.insert(std::pair<std::string, std::string>(line.substr(0, sepIdx), line.substr(sepIdx + 1)));
}

void	BitcoinExchange::parse_db( void )
{
	int i = 1;
	for (std::map<std::string, std::string>::iterator it = this->_db.begin(); it != this->_db.end(); it++)
	{
		std::string date = it->first;
		std::string value = it->second;
		if (!parse_date(date))
			throw BitcoinExchange::BadInputException(i);
		is_pflaot(value);
		i++;
	}
}

bool BitcoinExchange::parse_date(std::string date)
{
	std::string year;
	std::string month;
	std::string day;
	std::size_t	sep1;
	std::size_t	sep2;

	sep1 = date.find('-');
	if (sep1 == std::string::npos)
		return (false);
	year = date.substr(0, sep1);
	sep2 = date.substr(sep1 + 1).find('-');
	if (sep2 == std::string::npos)
		return (false);
	month = date.substr(sep1 + 1, sep2);
	day = date.substr(date.find_last_of("-") + 1);

	if (month.length() != 2 || day.length() != 2 || !is_integer(year) || ! is_integer(day) || !is_integer(month))
		return (false);

	// std::cout << "year: " << year << ", month: " << month << ", day: " << day << std::endl;
	return (true);
}

bool BitcoinExchange::is_integer(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (!(*it >= '0' && *it <= '9'))
			return (false);
	}
	return (true);
}

bool BitcoinExchange::check_date(std::string syear, std::string smonth, std::string sday)
{
	int	year;
	int	day;
	int	month;
	std::stringstream str;

	str << syear;
	str >> year;

	str.str("");
	str << smonth;
	str >> month;

	str.str("");
	str << sday;
	str >> day;

	if (year == 0 || day == 0 || month == 0 || month > 12)
		return (false);
	if (is_leap_year(year) && month == 2 && day > 29)
		return (false);
	else if (month == 2 && day > 28)
		return (false);
	return (true);
}


bool BitcoinExchange::is_leap_year(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
				return (true);
	}
	return (false);
}

bool BitcoinExchange::is_pflaot(std::string str)
{
	if (str.at(0) == '-')
		throw BitcoinExchange::NotAPositiveNumberException();
	std::string::iterator it = str.begin();
	for (; it != str.end(); it++)
	{
		if (*it == '.')
			break ;
		if (!(*it >= '0' && *it <= '9'))
			throw false;
	}
	if (it == str.end())
		return (true);
	it++;
	for (; it != str.end(); it++)
	{
		if (!(*it >= '0' && *it <= '9'))
			return (false);
	}
	return (true);
}
