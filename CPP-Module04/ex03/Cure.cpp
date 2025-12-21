#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
	std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure Destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src) {
	std::cout << "Cure Copy Assignment Operator called" << std::endl;
	(void)src;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
