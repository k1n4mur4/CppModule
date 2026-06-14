#include "ScalarConverter.hpp"

static bool	isFloatPseudo(const std::string& literal) {
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	return false;
}

static bool	isDoublePseudo(const std::string& literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	return false;
}

static bool	isPseudoLiteral(const std::string& s) {
	return (isFloatPseudo(s) || isDoublePseudo(s));
}

static bool isFloatLiteral(const std::string& literal) {
	if (literal.empty())
		return false;
	if (isPseudoLiteral(literal))
		return true;

	bool hasPoint = false;

	for (std::string::size_type i = 0; i < literal.size(); i++) {
		char c = literal[i];

		if (i == 0 && (c == '+' || c == '-'))
			continue;
		if (std::isdigit(static_cast<unsigned char>(c))) {
			continue;
		}
		if (c == '.') {
			if (hasPoint)
				return false;
			hasPoint = true;
			continue;
		}
		if (c == 'f') {
			if (i != literal.size() - 1)
				return false;
			continue;
		}
		return false;
	}
	return true;
}

static bool isIntLiteral(const std::string& literal) {
	if (literal.empty())
		return false;
	std::string::size_type i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	if (i == literal.size())
		return false;
	for (; i < literal.size(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return false;
	}
	return true;
}

static void	convertChar(const std::string& literal) {
	if (literal.size() == 0) {
		std::cout << "char: Non displayable" << std::endl;
		return ;
	} else if (!isFloatLiteral(literal) && !isIntLiteral(literal) && literal.size() != 1) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char* end = NULL;
	double d = static_cast<double>(std::strtod(literal.c_str(), &end));
	if (end == literal.c_str()) {
		if (literal.size() == 1)
			std::cout << "char: '" << literal << "'" << std::endl;
		else if (literal.size() == 0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d)) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(d);
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void	convertInt(const std::string& literal) {
	if (isPseudoLiteral(literal) || !isFloatLiteral(literal)) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	char* end = NULL;
	double d = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str()) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN) || std::isnan(d) || std::isinf(d)) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	int i = static_cast<int>(d);
	std::cout << "int: " << i << std::endl;
}

void	convertFloat(const std::string& literal) {
	// Size
	std::string::size_type Size = literal.size();

	// fSize
	std::string::size_type fSize = 0;
	if (!literal.empty() && literal[literal.size() - 1] == 'f')
		fSize = 1;

	// Point
	bool hasPoint = (literal.find('.') != std::string::npos);
	std::string::size_type pointSize = 0;
	if (hasPoint)
		pointSize = literal.find('.');

	// Sign
	bool hasplus = (literal.find('+') != std::string::npos);

	// precisionSize
	std::string::size_type precisionSize = 1;
	if (pointSize != 0)
		precisionSize = Size - pointSize - 1 - fSize;

	// convert
	char* end = NULL;
	float f = static_cast<float>(std::strtof(literal.c_str(), &end));
	if (end == literal.c_str() || !isFloatLiteral(literal)) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: ";
		if (hasplus)
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(precisionSize)
				<< f << "f" << std::endl;
	}
}

void	convertDouble(const std::string& literal) {
	// Size
	std::string::size_type Size = literal.size();

	// fSize
	std::string::size_type fSize = 0;
	if (!literal.empty() && literal[literal.size() - 1] == 'f')
		fSize = 1;

	// Point
	bool hasPoint = (literal.find('.') != std::string::npos);
	std::string::size_type pointSize = 0;
	if (hasPoint)
		pointSize = literal.find('.');

	// Sign
	bool hasplus = (literal.find('+') != std::string::npos);

	// precisionSize
	std::string::size_type precisionSize = 1;
	if (pointSize != 0)
		precisionSize = Size - pointSize - 1 - fSize;

	// convert
	char *end = NULL;
	double d = static_cast<double>(std::strtod(literal.c_str(), &end));
	if (end == literal.c_str() || !isFloatLiteral(literal)) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: ";
		if (hasplus)
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(precisionSize)
				<< d << std::endl;
	}
}

#ifdef DEBUG
# include <cmath>
void	convertDebug(const std::string& literal) {
	// std::cout << "--------------------------convertDebug----------------------------" << std::endl;
	std::cout << literal << std::endl;

	// std::cout << "------------------------------------------------------------------" << std::endl;
}
#endif

void	ScalarConverter::convert(const std::string& literal) {
#ifdef DEBUG
	convertDebug(literal);
#endif
	convertChar(literal);
	convertInt(literal);
	convertFloat(literal);
	convertDouble(literal);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
	return *this;
}