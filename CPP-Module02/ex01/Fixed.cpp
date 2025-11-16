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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
