#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _fixedPointValue(n << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _fixedPointValue(roundf(f * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_fixedPointValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int		Fixed::toInt( void ) const {
	return _fixedPointValue >> _fractionalBits;
}

int	Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

bool Fixed::operator>(const Fixed& other) const {
	return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
	return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
	return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((_fixedPointValue << _fractionalBits) / other._fixedPointValue);
	return result;
}

Fixed& Fixed::operator++() {
	_fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_fixedPointValue += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	_fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_fixedPointValue -= 1;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}
