#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	loadDatabase(const std::string& filename);
		bool	isValidDate(const std::string& date);
		double	getRate(const std::string& date) const;

	private:
		std::map<std::string, double>	_db;
};

#endif
