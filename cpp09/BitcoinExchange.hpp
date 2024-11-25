#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <exception>
#include <fstream>
#include <ctime>

#define FORMAT "%Y-%m-%d"
#define DB_NAME "data.csv"

class BitcoinExchange
{
	private:
		std::string	_inputFile;
		std::ifstream infile_stream;
		std::map<std::string, std::string> _db;
		void	loadInfile( void );
		void	loadDb( void );
	public:
		~BitcoinExchange();
		BitcoinExchange();
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);

		//Public Member Functions
		void	displayDB( void );
		void 	save_line(std::string line, int fline);
		void	parse_db( void );

		static bool parse_date(std::string date);
		static bool check_date(std::string syear, std::string smonth, std::string sday);
		static bool is_integer(std::string str);
		static bool is_pflaot(std::string str);
		static bool is_leap_year(int year);
		static bool check_value(std::string value);

		// Getter
		std::map<std::string, std::string>& getMap( void );


		// Exceptions
		class BadInputException: public std::exception
		{
			private:
				int	line;
			public:
				BadInputException(int line):line(line){}
				const char * what() const throw();
		};
		class NotAPositiveNumberException: public std::exception
		{
			const char * what() const throw();
		};

		class TooLargeNumberException: public std::exception
		{
			const char * what() const throw();
		};

		class CouldNotOpenFileException: public std::exception
		{
			const char * what() const throw();
		};
};

#endif