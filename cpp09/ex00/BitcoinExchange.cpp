#include "BitcoinExchange.hpp"

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
			throw std::runtime_error("Error: wrong header.");
		int fline = 2;
		while (std::getline(database, line))
		{
			this->save_line(line, fline);
			fline++;
		}
		parse_db();
	}
	else
		throw std::runtime_error("Error: could not open file.");
}

void	BitcoinExchange::loadInfile( void )
{
	std::string line;
	std::getline(this->infile_stream, line);
	if (line.compare("date | value"))
		std::cout << "Wrong Header" << std::endl;
	while (std::getline(this->infile_stream, line))
	{
		try
		{
			parse_infile(line, _db);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

/* ************************************************************************** */
/*                             Canonical Form                                 */
/* ************************************************************************** */

BitcoinExchange::~BitcoinExchange(){}


BitcoinExchange::BitcoinExchange(): _inputFile("input.txt")
{
	this->loadDb();
	this->infile_stream.open(this->_inputFile.c_str(), std::ios::in);
	if (this->infile_stream.is_open())
	{
		this->loadInfile();
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
	}
}


BitcoinExchange::BitcoinExchange(std::string inputFile): _inputFile(inputFile)
{
	this->loadDb();
	this->infile_stream.open(this->_inputFile.c_str(), std::ios::in);
	if (this->infile_stream.is_open())
	{
		this->loadInfile();
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
	}
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
		throw std::runtime_error(concat_str("bad input", fline));
	else
		this->_db.insert(std::pair<std::string, std::string>(line.substr(0, sepIdx), line.substr(sepIdx + 1)));
}

void	BitcoinExchange::parse_db( void )
{
	int i = 2;
	for (std::map<std::string, std::string>::iterator it = this->_db.begin(); it != this->_db.end(); it++)
	{
		std::string date = it->first;
		std::string value = it->second;
		try
		{
			parse_date(date, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << date << " " << e.what() << '\n';
			break ;
		}
		try
		{
			check_value_db(value, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << value << " " << e.what() << '\n';
			break ;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                             Public Static member functions                 */
/* ************************************************************************** */

std::string&	BitcoinExchange::get_closest_value(std::string date, std::string value, std::map<std::string, std::string> _db)
{
	static std::string empty = "DataBase is Empty";
	static std::string ret;
	std::map<std::string, std::string>::iterator next;
	std::stringstream str;
	float dbval;
	float val;

	if (_db.size() == 0)
		return (empty);
	std::map<std::string, std::string>::iterator it = _db.begin();
	if (date.compare(it->first) < 0)
		throw (std::runtime_error("Error: no smaller date in database than " + date));
	for (; it != _db.end(); it++)
	{
		if (!it->first.compare(date))
		{
			ret = it->second;
			break ;
		}
		next = it;
		next++;
		if  (next == _db.end() || next->first > date)
		{
			ret = it->second;
			break ;
		}
	}
	str << value;
	str >> dbval;
	str.clear();
	str << ret;
	str >> val;

	float mult = dbval * val;
	static std::string answer;
	str.clear();
	str << mult;
	str >> answer;
	return (answer);

}

void BitcoinExchange::parse_infile(std::string str, std::map<std::string, std::string> _db)
{
	std::string date;
	std::string year;
	std::string month;
	std::string day;
	std::size_t separator;
	std::size_t	sep1;
	std::size_t	sep2;
	std::string	value;
	std::stringstream sstr;

	separator = str.find(" | ");
	if (separator == std::string::npos)
		throw std::runtime_error("Error: bad input => " + str);
	date = str.substr(0, separator);
	sep1 = date.find('-');
	if (sep1 == std::string::npos)
		throw std::runtime_error("Error: bad input => " + str);
	year = date.substr(0, sep1);
	sep2 = date.substr(sep1 + 1).find('-');
	if (sep2 == std::string::npos)
		throw std::runtime_error("Error: bad input => " + str);
	month = date.substr(sep1 + 1, sep2);
	day = date.substr(date.find_last_of("-") + 1);
	if (month.length() != 2 || day.length() != 2 || !is_integer(year) || !is_integer(day) || !is_integer(month) || !check_date(year, month, day))
		throw std::runtime_error("Error: bad input => " + date);
	value = str.substr(separator + 3);
	check_value(value, -1);
	std::cout << year << "-" << month << "-" << day << " => " << value << " = " << get_closest_value(date, value, _db) << std::endl;
}

void BitcoinExchange::parse_date(std::string date, int line)
{
	std::string year;
	std::string month;
	std::string day;
	std::size_t	sep1;
	std::size_t	sep2;

	sep1 = date.find('-');
	if (sep1 == std::string::npos)
		throw std::runtime_error(concat_str("bad input", line));
	year = date.substr(0, sep1);
	sep2 = date.substr(sep1 + 1).find('-');
	if (sep2 == std::string::npos)
		throw std::runtime_error(concat_str("bad input", line));
	month = date.substr(sep1 + 1, sep2);
	day = date.substr(date.find_last_of("-") + 1);

	if (month.length() != 2 || day.length() != 2 || !is_integer(year) || ! is_integer(day) || !is_integer(month) || !check_date(year, month, day))
		throw std::runtime_error(concat_str("bad input", line));
}

bool BitcoinExchange::check_date(std::string syear, std::string smonth, std::string sday)
{
	int	year;
	int	day;
	int	month;
	std::stringstream str;

	str << syear;
	str >> year;

	str.clear();
	str << smonth;
	str >> month;

	str.clear();
	str << sday;
	str >> day;

	if (year == 0 || day == 0 || month == 0 || month > 12)
		return (false);
	if (is_leap_year(year) && month == 2 && day > 29)
		return (false);
	else if (!is_leap_year(year) && month == 2 && day > 28)
		return (false);
	if (month != 2)
	{
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return (false);
		else if (day > 31)
			return (false);
	}
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

void BitcoinExchange::is_pflaot(std::string str, int line)
{
	std::string::iterator it = str.begin();
	if (*it == '-')
		it++;
	for (; it != str.end(); it++)
	{
		if (*it == '.')
			break ;
		if (!(*it >= '0' && *it <= '9'))
			throw std::runtime_error(concat_str("bad input => " + str, line));
	}
	if (it == str.end())
		return ;
	it++;
	for (; it != str.end(); it++)
	{
		if (!(*it >= '0' && *it <= '9'))
			throw std::runtime_error(concat_str("bad input => " + str, line));
	}
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


std::string &BitcoinExchange::concat_str(std::string error, int line)
{
	static std::string message;
	std::stringstream str;
	str << error;
	if (line > 0)
	{
		str << " at line: ";
		str << line;
	}
	message = str.str();
	return message;
}

void BitcoinExchange::check_value(std::string value, int line )
{
	is_pflaot(value, line);
	double fvalue;
	std::stringstream str;
	str << value;
	str >> fvalue;
	if (fvalue > 1000)
	{
		throw std::runtime_error(concat_str("Error: too large a number.", line));
	}
	if (fvalue < 0.0)
		throw std::runtime_error(concat_str("Error: not a positive number.", line));
}

void BitcoinExchange::check_value_db(std::string value, int line )
{
	is_pflaot(value, line);
	double fvalue;
	std::stringstream str;
	str << value;
	str >> fvalue;
	if (fvalue > 2147483647)
	{
		throw std::runtime_error(concat_str("Error: too large a number.", line));
	}
	if (fvalue < 0.0)
		throw std::runtime_error(concat_str("Error: not a positive number.", line));
}

/* ************************************************************************** */
/*                           	  Getter                             	      */
/* ************************************************************************** */

std::map<std::string, std::string>& BitcoinExchange::getMap( void )
{
	return (this->_db);
}
