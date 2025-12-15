#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria Default Constructor" << std::endl;
	this->_type = "default";
}

AMateria::AMateria(std::string const &type) {
	std::cout << "AMateria Type Constructor" << std::endl;
	this->_type = type;
}


AMateria::AMateria(const AMateria &src) : _type(src._type) {
	std::cout << "AMateria Copy Constructor" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src) {
	(void)src;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
