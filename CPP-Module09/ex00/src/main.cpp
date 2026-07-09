#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

# define DB_FILE "./data/data.csv"
# define HEADER "date | value"

namespace Color {
	const char *BOLD = "\033[1m";
	const char *BOLD_UNDERLINE = "\033[1;4m";
	const char *BOLD_RED = "\033[1;31m";
	const char *RESET = "\033[0m";
}

static void error(std::string msg) {
	std::cerr << Color::BOLD_RED << "Error:" << Color::RESET << " " << msg << std::endl;
}

static void msg(std::string msg) {
	std::cout << Color::BOLD_RED << "Error:" << Color::RESET << " " << msg << std::endl;
}

static void processLine(BitcoinExchange& be, const std::string& line) {

	std::string::size_type pos = line.find(" | ");
	if (pos == std::string::npos) {
		msg("bad input => " + line);
		return;
	}

	std::string date = line.substr(0, pos);
	if (!be.isValidDate(date)) {
		msg("bad input => " + line);
		return;
	}

	std::string valueStr = line.substr(pos + 3);
	double value;
	std::stringstream ss(valueStr);
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		msg("bad input => " + line);
		return;
	}
	if (value < 0) {
		msg("not a positive number.");
		return;
	}
	if (value > 1000) {
		msg("too large a number.");
		return;
	}

	try {
		double rate = be.getRate(date);
		std::cout << date << " => " << valueStr << " = " << value * rate << std::endl;
	} catch (std::exception &e) {
		msg(e.what());
	}
}

int main(int argc, char *argv[] ) {

	if (argc != 2) {
		error("could not open file.");
		return 1;
	}

	BitcoinExchange be;
	try {
		be.loadDatabase(DB_FILE);
	} catch (std::exception &e) {
		error(e.what());
		return 1;
	}

	std::string filename = argv[1];
	#ifdef DEBUG
		std::cout << Color::BOLD << "----- DEBUG MODE -----" << Color::RESET << std::endl;
		std::cout << "filename:" << filename << std::endl;
	#endif

	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open()) {
		error("could not open file.");
		return 1;
	}

	std::string line;
	bool first = true;
	while (std::getline(ifs, line)) {
		#ifdef DEBUG
			std::cout << line << std::endl;
		#endif

		if (first) {
			first = false;
			if (line == HEADER)
				continue;
		}
		processLine(be, line);
	}

	return 0;
}
