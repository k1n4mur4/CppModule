#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &src) : AMateria(src) {
}

Ice::~Ice() {

}

Ice &Ice::operator=(const Ice &src) {
	(void)src;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
