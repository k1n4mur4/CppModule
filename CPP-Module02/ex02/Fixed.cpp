#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(0) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
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
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int		Fixed::toInt( void ) const {
	return this->_fixedPointValue >> _fractionalBits;
}

int	Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

bool Fixed::operator>(const Fixed &other) const {
	return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
	return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
	return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
	return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long long temp = (long long)this->_fixedPointValue * (long long)other._fixedPointValue;
	result.setRawBits((int)(temp>> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits((_fixedPointValue / other._fixedPointValue) >> _fractionalBits);
	return result;
}

Fixed& Fixed::operator++(void) {
	_fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_fixedPointValue += 1;
	return temp;
}

Fixed& Fixed::operator--(void) {
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
