#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other){
		this->_db = other._db;
	}
	return *this;
}

void	BitcoinExchange::loadDatabase(const std::string& filename) {

	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
		throw std::runtime_error("could not open database.");

	std::string line;
	if (std::getline(ifs, line)) {
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
			throw std::runtime_error("invalid format.");
	}

	while (std::getline(ifs, line)) {
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
			continue;

		std::string	date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 1);

		double	value;
		std::stringstream ss(valueStr);
		ss >> value;

		_db[date] = value;
	}

	ifs.close();

	#ifdef DEBUG
		std::map<std::string, double>::const_iterator it;
		for (it = _db.begin(); it != _db.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	#endif

}

double	BitcoinExchange::getRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

	if (it != _db.end() && it->first == date)
		return it->second;

	if (it == _db.begin())
		throw std::runtime_error("no earlier date in database.");

	--it;
	return it->second;

}

bool	BitcoinExchange::isValidDate(const std::string& date) {

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	int year, month, day;

	std::stringstream ssy(date.substr(0, 4));
	ssy >> year;
	if (ssy.fail() || !ssy.eof()) {
		return false;
	}

	std::stringstream ssm(date.substr(5, 2));
	ssm >> month;
	if (ssm.fail() || !ssm.eof()) {
		return false;
	}

	std::stringstream ssd(date.substr(8, 2));
	ssd >> day;
	if (ssd.fail() || !ssd.eof()) {
		return false;
	}

	if (month < 1 || month > 12)
		return false;

	static const int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	maxDay = daysInMonth[month - 1];
	if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		maxDay = 29;
	if (day < 1 || day > maxDay)
		return false;
	return true;
}
