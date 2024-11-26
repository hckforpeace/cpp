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

		// Static Member Functions
		static void parse_date(std::string date, int line);
		static bool check_date(std::string syear, std::string smonth, std::string sday);
		static bool is_integer(std::string str);
		static void is_pflaot(std::string str, int line);
		static bool is_leap_year(int year);
		static std::string &concat_str(std::string error, int line);
		static void check_value(std::string value, int line);

		// Getter
		std::map<std::string, std::string>& getMap( void );


		// Exceptions
		class BadInputException: public std::exception
		{
			public:
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