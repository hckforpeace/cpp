#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <exception>
#include <fstream>
#include <ctime>
#include <string>

#define FORMAT "%Y-%m-%d"
#define DB_NAME "empty.csv"

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

		void parse_save_line(std::string line);


		// Getter
		std::map<std::string, std::string>& getMap( void );

		// Exceptions
		class BadInputException: public std::exception
		{
			const char * what(unsigned int line) const throw();
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